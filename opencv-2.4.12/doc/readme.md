编译
==============
	cd opencv-2.4.12/platforms/linux
	mkdir build_hardfp
	cd build_hardfp
	cmake -DCMAKE_TOOLCHAIN_FILE=../arm-gnueabi.toolchain.cmake ../../..
	make
	make install

生成的文件在：opencv-2.4.12/platforms/linux/build_hardfp/install


makefile
=============
参考了：opencv-2.4.12/platforms/linux/build_hardfp/install/lib/pkgconfig/opencv.pc

运行
======
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/opencv_lib


gtk支持
====
待续

qt支持
=======
