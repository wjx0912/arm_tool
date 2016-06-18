编译：

CC=arm-linux-gnueabihf-gcc   ./configure --host=arm-linux

make CFLAGS+="-static" V=1

本工程的strace已经静态编译，可以直接拷到arm里面使用
