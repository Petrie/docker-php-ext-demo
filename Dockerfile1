FROM petrie/php:7.2.6-fpm-stretch
RUN apt-get -y update
RUN apt-get -y install valgrind
RUN docker-php-source extract;
RUN mkdir /data
WORKDIR /data
RUN chmod +x /usr/src/php/ext/ext_skel
ENTRYPOINT /usr/src/php/ext/ext_skel --extname=calc --skel=/usr/src/php/ext/skeleton/ 