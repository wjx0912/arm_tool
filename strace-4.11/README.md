编译：

CC=arm-fsl-linux-gnueabi   ./configure --host=arm-linux

make CFLAGS+="-static"
