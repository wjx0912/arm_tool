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

#include <iostream>

#include "opencv2/core/core.hpp"
#include "../include/OpencvWrap.h"

COpenCVWrap *m_instance = NULL;

COpenCVWrap* COpenCVWrap::getInstance()
{
	if(NULL == m_instance)
		m_instance = new COpenCVWrap();
	return m_instance;
}

int COpenCVWrap::init()
{
	std::cout << cv::getBuildInformation() << std::endl;
	return 0;
}

int COpenCVWrap::setline(struct WarningLine *line)
{
	return 0;
}

bool COpenCVWrap::processimage(void *imagebuffer, int width, int height, struct WarningLine *linearray[])
{
	return false;
}

