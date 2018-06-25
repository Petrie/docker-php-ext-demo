--TEST--
Check for calc presence
--SKIPIF--
<?php if (!extension_loaded("calc")) print "skip"; ?>
--FILE--
<?php 
$mc = new mycalc();
echo $mc::add(3,4).PHP_EOL;
echo calc_sub(9,1).PHP_EOL;
var_dump(multiple_fahrenheit_to_celsius(
[1,2,3]
))
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
7
8