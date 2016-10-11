#! /bin/bash
export CC=arm-none-linux-gnueabi-gcc
export AR=arm-none-linux-gnueabi-ar
export LD=arm-none-linux-gnueabi-ld
export RANLIB=arm-none-linux-gnueabi-ranlib
export STRIP=arm-none-linux-gnueabi-strip 

./configure --prefix=/opt/lighttpd-1.4.41-arm --host=arm-linux --build=i686-pc-linux --disable-FEATURE --enable-shared --disable-static --disable-lfs --disable-ipv6 --without-PACKAGE --without-valgrind --without-openssl --without-kerberos5 --without-pcre --without-zlib --without-bzip2 --without-lua
 make V=1

