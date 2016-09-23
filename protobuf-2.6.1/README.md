先编译x86版本得到protoc，再编译arm：

CC=arm-linux-gnueabihf-gcc   CXX=arm-linux-gnueabihf-g++  ./configure --host=arm-linux --with-protoc=protoc --disable-shared

编辑./config.h 增加：#define HAVE_PTHREAD

make CFLAGS+="-static" V=1

本工程的strace已经静态编译，可以直接拷到arm里面使用


CC=arm-none-linux-gnueabi-gcc CXX=arm-none-linux-gnueabi-g++ ./configure --host=arm-linux --disable-shared
make CFLAGS+="-static" V=1



编译最后有错误：到这里会蹦出一个错误，原因是在x86上执行arm版本的protoc编译.proto测试文件，把x86的拷贝到src/.libs下面