编译：

CC=arm-linux-gnueabihf-gcc   CXX=arm-linux-gnueabihf-g++  ./configure --host=arm-linux --with-protoc=protoc --disable-shared

编辑./config.h 增加：#define HAVE_PTHREAD

make CFLAGS+="-static" V=1

本工程的strace已经静态编译，可以直接拷到arm里面使用
