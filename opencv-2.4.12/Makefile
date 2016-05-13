CC=arm-linux-gnueabihf-g++
AR=arm-linux-gnueabihf-ar

CFLAGS := -O2 -DLINUX -w -fpermissive -I../
LFLAGS := -lrt -lpthread -lm -ldl


OPENCV_INSTALL	:=	/home/clock/opencv-2.4.12/platforms/linux/build_hardfp/install
OPENCV_CFLAGS	:=	-I$(OPENCV_INSTALL)/include
OPENCV_LDFLAGS	:=	-L$(OPENCV_INSTALL)/lib											\
			-lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu 	\
			-lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect 	\
			-lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video 		\
			-lopencv_videostab -lrt -lpthread -lm -ldl


all:
	$(CC) $(CFLAGS) $(OPENCV_CFLAGS) src/*.cpp -c
	$(AR) rcs lib/opencv_wrap.a *.o
	rm *.o -f
	$(CC)  $(CFLAGS) $(OPENCV_CFLAGS) test/*.cpp lib/opencv_wrap.a -o bin/opencv_test $(OPENCV_LDFLAGS) $(LFLAGS)
	ls -l lib/ --color
	ls -l bin/ --color
	cp bin/opencv_test /home/clock -f


clean:
	rm *.o   -f
	rm lib/* -f
	rm bin/* -f

