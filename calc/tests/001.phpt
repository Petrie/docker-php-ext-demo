--TEST--
Check for calc presence
--SKIPIF--
<?php /*if (!extension_loaded("calc")) */print "skip"; ?>
--FILE--
<?php 
$obj = new myclass();
$obj->public_var = 1;
echo $obj->public_var;
/*
	you can add regression tests for your extension here

  the output of your test code has to be equal to the
  text in the --EXPECT-- section below for the tests
  to pass, differences between the output and the
  expected text are interpreted as failure

	see php7/README.TESTING for further information on
  writing regression tests
*/
?>
--EXPECT--
I'm __construct
1