#!/bin/sh

case "$1" in
make)
	sh ./buildcalc.sh
;;

test)
	docker run --rm --entrypoint="" --workdir="/calc" \
-v $PWD/calc:/calc php:7.2.6-extension-calc \
sh -c "export TEST_PHP_EXECUTABLE=/usr/local/bin/php &&
/usr/local/bin/php run-tests.php --show-out --show-exp"
;;

run)
	shift
	docker run --rm --entrypoint="" --workdir="/calc" \
-v $PWD/calc:/calc php:7.2.6-extension-calc \
$@
;;

*)
	sh $0 make
	sh $0 test
;;
esac
#docker run -ti --rm --entrypoint="" --workdir="/calc" -v $PWD/calc:/calc php:7.2.6-extension /bin/bash
#docker run -ti --rm --entrypoint="" --workdir="/calc" -v $PWD/calc:/calc php:7.2.6-extension-calc /bin/bash