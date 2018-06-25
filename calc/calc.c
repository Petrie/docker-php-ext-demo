
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_calc.h"

/* If you declare any globals in php_calc.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(calc)
*/

/* True global resources - no need for thread safety here */
static int le_calc;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("calc.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_calc_globals, calc_globals)
    STD_PHP_INI_ENTRY("calc.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_calc_globals, calc_globals)
PHP_INI_END()
*/
/* }}} */

/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/



/* {{{ php_calc_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_calc_init_globals(zend_calc_globals *calc_globals)
{
	calc_globals->global_value = 0;
	calc_globals->global_string = NULL;
}
*/
/* }}} */


zend_class_entry *myclass_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_mycalc_add, 0, 0, 2)
    ZEND_ARG_INFO(0, num1)
    ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_METHOD(mycalc, add)
{
	long num1, num2 ;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &num1, &num2) == FAILURE){
		return;
	}
	RETURN_LONG(num1 + num2);
}

/*
PHP_METHOD(myclass1, public_method);
PHP_METHOD(myclass1, __construct);
*/
zend_function_entry mycalc_methods[]=
{
		ZEND_ME(mycalc, add, arginfo_mycalc_add, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
		{NULL, NULL, NULL}
};

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(calc)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	 zend_class_entry ce;
	 INIT_CLASS_ENTRY(ce, "mycalc", mycalc_methods);
	 myclass_ce = zend_register_internal_class(&ce TSRMLS_CC);
	 zend_declare_property_double(myclass_ce, "num1", strlen("num1"), 0,ZEND_ACC_PUBLIC TSRMLS_CC);
	 zend_declare_property_double(myclass_ce, "num2", strlen("num2"), 0,ZEND_ACC_PUBLIC TSRMLS_CC);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(calc)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(calc)
{
	 zend_class_entry ce;
	 INIT_CLASS_ENTRY(ce, "mycalc", mycalc_methods);
	 myclass_ce = zend_register_internal_class(&ce TSRMLS_CC);

#if defined(COMPILE_DL_CALC) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(calc)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(calc)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "calc support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


ZEND_FUNCTION(academy_hello)
{
    php_printf("Hello Laravel Academy!\n");
}

ZEND_FUNCTION(sample_long)
{
	RETVAL_LONG(42);
	return;
}
ZEND_FUNCTION(sample_getlong) {
    long foo;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &foo) == FAILURE)
    {
        RETURN_NULL();
    }
    php_printf("The integer value of the parameter is: %ld\n", foo);
    RETURN_TRUE;
}

ZEND_FUNCTION(sample_hello_world)
{
    char *name;
    size_t name_len;
    zend_string *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE)
    {
            RETURN_NULL();
    }
    strg = strpprintf(0, "Hello %s ", name);
    RETURN_STR(strg);
}

ZEND_FUNCTION(addition) {
	long num1, num2;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &num1, &num2) == FAILURE) {
		return;
	}
	RETURN_LONG(num1 + num2);
}



ZEND_FUNCTION(sample_count_array)
{
    zval *arr;
    if (zend_get_parameters(ZEND_NUM_ARGS() TSRMLS_CC, 1, &arr) == FAILURE)
    {
        RETURN_NULL();
    }
    RETURN_LONG(zend_hash_num_elements(Z_ARRVAL_P(arr)));
}

ZEND_BEGIN_ARG_INFO(php_sample_array_arginfo, 0)
    ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()



ZEND_FUNCTION(calc_add)
{
	long num1, num2 ;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &num1, &num2) == FAILURE){
		return;
	}
	RETURN_LONG(num1 + num2);
}

ZEND_FUNCTION(calc_sub)
{
	double num1, num2;

	ZEND_PARSE_PARAMETERS_START(2 ,2 )
		Z_PARAM_DOUBLE(num1)
		Z_PARAM_DOUBLE(num2)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_DOUBLE(num1 - num2);
}

ZEND_FUNCTION(calc_mult)
{
	size_t num1, num2;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll", &num1, &num2) == FAILURE){
		return;
	}
	RETURN_LONG(num1*num2)
}
ZEND_FUNCTION(calc_div)
{
	size_t num1, num2;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll", &num1, &num2) == FAILURE){
		return;
	}
	if (num2 == 0){
	    php_printf("num2 can be zero\n");
	    return;
	}
	RETURN_LONG(num1/num2)
}


static double php_celsius_to_fahrenheit(double c)
{
    return (((double)9/5) * c) + 32 ;
}

static double php_fahrenheit_to_celsius(double f)
{
    return ((double)5/9) * (double)(f - 32);
}


ZEND_BEGIN_ARG_INFO_EX(arginfo_multiple_fahrenheit_to_celsius,0,0,1)
	ZEND_ARG_ARRAY_INFO(0, temperatures, 0)
ZEND_END_ARG_INFO();

static const zend_function_entry pib_functions[]=
{
		PHP_FE(multiple_fahrenheit_to_celsius, arginfo_multiple_fahrenheit_to_celsius)
		PHP_FE_END
};

PHP_FUNCTION(multiple_fahrenheit_to_celsius)
{
	HashTable *temperatures;
	zval *data;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "h", &temperatures) == FAILURE){
		return;
	}

	if(zend_hash_num_elements(temperatures) == 0){
		return;
	}
	array_init_size(return_value, zend_hash_num_elements(temperatures));

	ZEND_HASH_FOREACH_VAL(temperatures, data)
		zval dup;
		ZVAL_COPY_VALUE(&dup, data);
		convert_to_double(&dup);
		add_next_index_double(return_value, php_fahrenheit_to_celsius(Z_DVAL(dup)));
	ZEND_HASH_FOREACH_END();

}


/* {{{ calc_functions[]
 *
 * Every user visible function must have an entry in calc_functions[].
 */
const zend_function_entry calc_functions[] = {
    ZEND_FE(academy_hello, NULL)
    ZEND_FE(sample_long, NULL)
    ZEND_FE(sample_getlong, NULL)
    ZEND_FE(sample_hello_world, NULL)
    ZEND_FE(addition, NULL)
    ZEND_FE(calc_add, arginfo_mycalc_add)
    ZEND_FE(calc_sub, NULL)
    ZEND_FE(calc_mult, NULL)
    ZEND_FE(calc_div, NULL)
	PHP_FE(multiple_fahrenheit_to_celsius, arginfo_multiple_fahrenheit_to_celsius)
	ZEND_FE(sample_count_array, php_sample_array_arginfo)
	PHP_FE_END	/* Must be the last line in calc_functions[] */
};
/* }}} */

/* {{{ calc_module_entry
 */
zend_module_entry calc_module_entry = {
	STANDARD_MODULE_HEADER,
	"calc",
	calc_functions,
	PHP_MINIT(calc),
	PHP_MSHUTDOWN(calc),
	PHP_RINIT(calc),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(calc),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(calc),
	PHP_CALC_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CALC
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(calc)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
