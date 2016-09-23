arm交叉编译最新protobuf版本3.0.2
=================
	tar zxf protobuf-3.0.2.tar.gz
	cd protobuf-3.0.2
	cp protobuf-3.0.2 protobuf-3.0.2_x86 -fr

编译x86版本，这个步骤必须的，编译过程不会报错
=================
	cd protobuf-3.0.2_x86
	./autogen.sh
	./configure
	make
	make install
	protoc  --version

编译arm版本
=================
	cd cd protobuf-3.0.2
	./autogen.sh                  这一步会依赖网络,不能用网络的自己看脚本，就几行代码
	CC=arm-none-linux-gnueabi-gcc CXX=arm-none-linux-gnueabi-g++ ./configure --host=arm-linux
	make V=1
	到这里会蹦出一个错误，原因是在x86上执行arm版本的protoc编译.proto测试文件
	cp protobuf-3.0.2_x86/src/.libs/lt-protoc          protobuf-3.0.2/src/
	cp protobuf-3.0.2_x86/src/.libs/protoc             protobuf-3.0.2/src/
	继续make V=1
	编译的库在：protobuf-3.0.2/src/.libs
