# docker-php-ext-demo
```sh
#!/bin/sh

case "$1" in
#编译安装测试扩展
make)
	docker build -f ./Dockerfile2 -t php:7.2.6-extension-calc .
;;
#执行单元测试
test)
	docker run --rm --entrypoint="" --workdir="/calc" \
	-v $PWD/calc:/calc php:7.2.6-extension-calc \
	sh -c "export TEST_PHP_EXECUTABLE=/usr/local/bin/php &&
	/usr/local/bin/php run-tests.php --show-out --show-exp"
;;
#用来执行查看docker环境，比如php版本
#示例 build.sh run php -v
run)
	shift
	docker run --rm --entrypoint="" --workdir="/calc" \
-v $PWD/calc:/calc php:7.2.6-extension-calc \
$@
;;

#用来生成扩展基础代码
#生成扩展基础代码
extension)
	docker build -f ./Dockerfile1 -t php:7.2.6-extension .
	docker run --rm -v $PWD:/data php:7.2.6-extension
;;
*)
	sh $0 make
	sh $0 test
;;
esac
#docker run -ti --rm --entrypoint="" --workdir="/calc" -v $PWD/calc:/calc php:7.2.6-extension /bin/bash
#docker run -ti --rm --entrypoint="" --workdir="/calc" -v $PWD/calc:/calc php:7.2.6-extension-calc /bin/bash
```
