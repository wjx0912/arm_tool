CC=arm-fsl-linux-gnueabi-gcc ./configure --host=arm-linux  --disable-FEUTARE -disable-ipv6 -disable-lfs --without-pcre  --without-zlib --without-bzip2


make CFLAGS+="-static" V=1

