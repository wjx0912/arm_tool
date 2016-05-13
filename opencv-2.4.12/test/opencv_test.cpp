#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/OpencvWrap.h"
#include "../../common/logwrap.h"

#define VIDEO_WIDTH		1920
#define VIDEO_HEIGHT		1080

int main(int argc, char *argv[])
{
	plog::init(plog::warning, "/home/root/log_opencv.csv", 1024 * 1024, 5);
	LOG_PRINT("compile at: %s, %s, %d", __DATE__, __TIME__, (int)time(0));

	COpenCVWrap *opencv_obj = COpenCVWrap::getInstance();
	opencv_obj->init();

	return 0;
}
