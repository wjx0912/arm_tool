#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <termios.h>

#define COMM_DEBUG_OUTPUT

// ========================================================================


typedef unsigned char			BYTE;
typedef unsigned short			WORD;
typedef signed int			LONG;
typedef unsigned int			DWORD;

typedef struct tagCOMM_ATTR
 {
	DWORD	baudrate;		
	BYTE	databits;
	BYTE	parity;
	BYTE	stopbits;	
	BYTE	reserved;
} COMM_ATTR;


enum comm_stopbits_t 
{
	COMM_ONESTOPBIT,
	COMM_ONE5STOPBITS,
	COMM_TWOSTOPBITS,
};

enum comm_parity_t 
{
	COMM_NOPARITY,
	COMM_ODDPARITY,
	COMM_EVENPARITY,
	COMM_MARK,
	COMM_SPACE,
};


#define COMM_PURGE_TXABORT			0x0001	
#define COMM_PURGE_RXABORT			0x0002	
#define COMM_PURGE_TXCLEAR			0x0004	
#define COMM_PURGE_RXCLEAR			0x0008	

int CommOpen(const char *devname);
int CommDestory(int fd_com);
int CommSetAttribute(int fd_com, COMM_ATTR *pattr);
int CommRead(int fd_com, void *pdata, DWORD nbytes);
int CommWrite(int fd_com, void *pdata, DWORD len);
int CommWriteHexString(int fd_com, const char *hexstring);
int CommPurge(int fd_com, DWORD dw_flags);			// flush,clear data

typedef int (*comm_read_cb)(const char *data, int len);


#define ERR_PRINT		perror
#define LIB_PRINT		printf

#define dprintfbin(buf, size) 					\
	do {							\
		int i; 						\
		for (i = 0; i < size - 1; i++){ 		\
			if (0 == i % 16){ 			\
				if (0 != i)			\
					printf("\n");		\
				printf("0x%04x: ", i); 		\
			}					\
			printf("%02x ", ((char*)buf)[i]);	\
		}						\
		printf("%02x\n", ((char*)buf)[i]); 		\
	} while(0)

// ========================================================================


int CommOpen(const char *devname)
{
	int fd_com = open(devname, O_RDWR);
	if (fd_com < 0)
	{
		ERR_PRINT("open com dev\n");
		return -1;
	}

	struct termios opt;
	memset(&opt, 0, sizeof(struct termios));
	tcgetattr(fd_com, &opt);
	cfmakeraw(&opt);
	return fd_com;
}

int CommDestory(int fd_com)
{
	if(fd_com >= 0)
	{
		close(fd_com);
	}
	return 0;
}

int CommSetAttribute(int fd_com, COMM_ATTR *pattr)
{
	int dev_fd = fd_com;
	struct termios opt;
	COMM_ATTR *attr = pattr;

	
	
	if (dev_fd < 0)
	{
		return -1;
	}

	memset(&opt, 0, sizeof(struct termios));
	tcgetattr(dev_fd, &opt);
	cfmakeraw(&opt);			

	
	printf("set baudrate %d\n", attr->baudrate);
	switch (attr->baudrate)
	{
		case 50:
			cfsetispeed(&opt, B50);
			cfsetospeed(&opt, B50);
			break;
		case 75:
			cfsetispeed(&opt, B75);
			cfsetospeed(&opt, B75);
			break;
		case 110:
			cfsetispeed(&opt, B110);
			cfsetospeed(&opt, B110);
			break;
		case 134:
			cfsetispeed(&opt, B134);
			cfsetospeed(&opt, B134);
			break;
		case 150:
			cfsetispeed(&opt, B150);
			cfsetospeed(&opt, B150);
			break;
		case 200:
			cfsetispeed(&opt, B200);
			cfsetospeed(&opt, B200);
			break;
		case 300:
			cfsetispeed(&opt, B300);
			cfsetospeed(&opt, B300);
			break;
		case 600:
			cfsetispeed(&opt, B600);
			cfsetospeed(&opt, B600);
			break;
		case 1200:
			cfsetispeed(&opt, B1200);
			cfsetospeed(&opt, B1200);
			break;
		case 1800:
			cfsetispeed(&opt, B1800);
			cfsetospeed(&opt, B1800);
			break;
		case 2400:
			cfsetispeed(&opt, B2400);
			cfsetospeed(&opt, B2400);
			break;
		case 4800:
			cfsetispeed(&opt, B4800);
			cfsetospeed(&opt, B4800);
			break;
		case 9600:
			cfsetispeed(&opt, B9600);
			cfsetospeed(&opt, B9600);
			break;
		case 19200:
			cfsetispeed(&opt, B19200);
			cfsetospeed(&opt, B19200);
			break;
		case 38400:
			cfsetispeed(&opt, B38400);
			cfsetospeed(&opt, B38400);
			break;
		case 57600:
			cfsetispeed(&opt, B57600);
			cfsetospeed(&opt, B57600);
			break;
		case 115200:
			cfsetispeed(&opt, B115200);
			cfsetospeed(&opt, B115200);
			break;
		case 230400:
			cfsetispeed(&opt, B230400);
			cfsetospeed(&opt, B230400);
			break;
		case 460800:
			cfsetispeed(&opt, B460800);
			cfsetospeed(&opt, B460800);
			break;
		case 500000:
			cfsetispeed(&opt, B500000);
			cfsetospeed(&opt, B500000);
			break;
		case 576000:
			cfsetispeed(&opt, B576000);
			cfsetospeed(&opt, B576000);
			break;
		case 921600:
			cfsetispeed(&opt, B921600);
			cfsetospeed(&opt, B921600);
			break;
		case 1000000:
			cfsetispeed(&opt, B1000000);
			cfsetospeed(&opt, B1000000);
			break;
		case 1152000:
			cfsetispeed(&opt, B1152000);
			cfsetospeed(&opt, B1152000);
			break;
		case 1500000:
			cfsetispeed(&opt, B1500000);
			cfsetospeed(&opt, B1500000);
			break;
		case 2000000:
			cfsetispeed(&opt, B2000000);
			cfsetospeed(&opt, B2000000);
			break;
		case 2500000:
			cfsetispeed(&opt, B2500000);
			cfsetospeed(&opt, B2500000);
			break;
		case 3000000:
			cfsetispeed(&opt, B3000000);
			cfsetospeed(&opt, B3000000);
			break;
		case 3500000:
			cfsetispeed(&opt, B3500000);
			cfsetospeed(&opt, B3500000);
			break;
		case 4000000:
			cfsetispeed(&opt, B4000000);
			cfsetospeed(&opt, B4000000);
			break;
		default:
			LIB_PRINT("unsupported baudrate %d\n", attr->baudrate);
			break;
	}

	
	switch (attr->parity)
	{
		case COMM_NOPARITY:		
			opt.c_cflag &= ~PARENB;	
			opt.c_iflag &= ~INPCK;	
			break;
		case COMM_ODDPARITY:		
			opt.c_cflag |= PARENB;	
			opt.c_cflag |= PARODD;	
			opt.c_iflag |= INPCK;	
			break;
		case COMM_EVENPARITY:		
			opt.c_cflag |= PARENB;	
			opt.c_cflag &= ~PARODD;	
			opt.c_iflag |= INPCK;	
		default:
			LIB_PRINT("unsupported parity %d\n", attr->parity);
			break;
	}

	
	opt.c_cflag &= ~CSIZE;
	switch (attr->databits)
	{
		case 5:
			opt.c_cflag |= CS5;
			break;
		case 6:
			opt.c_cflag |= CS6;
			break;
		case 7:
			opt.c_cflag |= CS7;
			break;
		case 8:
			opt.c_cflag |= CS8;
			break;
		default:
			LIB_PRINT("unsupported data bits %d\n", attr->databits);
			break;
	}

	
	opt.c_cflag &= ~CSTOPB;
	switch (attr->stopbits)
	{
		case COMM_ONESTOPBIT:
			opt.c_cflag &= ~CSTOPB;
			break;

		case COMM_TWOSTOPBITS:
			opt.c_cflag |= CSTOPB;
			break;
		default:
			LIB_PRINT("unsupported stop bits %d\n", attr->stopbits);
			break;
	}
	opt.c_cc[VTIME]	= 0;
	opt.c_cc[VMIN]	= 1;			

	tcflush(dev_fd, TCIOFLUSH);
	if (tcsetattr(dev_fd, TCSANOW, &opt) < 0)
	{
		ERR_PRINT("tcsetattr\n");
		return -1;
	}

	return 0;
}

int CommRead(int fd_com, void *pdata, DWORD nbytes)
{
	if (fd_com < 0)
		return -1;

	return read(fd_com, pdata, nbytes);
}

int CommWrite(int fd_com, void *pdata, DWORD len)
{
	if (fd_com < 0)
		return -1;

	return write(fd_com, pdata, len);
}

int CommWriteHexString(int fd_com, const char *hexstring)
{
	if(fd_com < 0 || strlen(hexstring) <= 0)
		return -1;

	char result[256] = "";
	int result_len = 0;

	const char *cur = hexstring;
	while(cur != NULL) {
		const char *p = strchr(cur, ' ');
		char buf[8];
		memset(buf, 0x0, 8);
		if(p) {
			memcpy(buf, cur, p - cur);
			cur = ++p;
		} else {
			strcpy(buf, cur);
			cur = NULL;
		}
		if(strlen(buf) <= 0)
			break;

		result[result_len++] = (int)strtoul(buf, 0x0, 16);
	}
	int len = CommWrite(fd_com, result, result_len);

#ifdef COMM_DEBUG_OUTPUT
	//printf("CommWriteHexString: %s, write result: %d\n", hexstring, len);
	dprintfbin(result, result_len);
#endif

	return 0;
}

int CommPurge(int fd_com, DWORD dw_flags)
{
	if (fd_com < 0)
		return -1;

	switch (dw_flags)
	{
		case COMM_PURGE_TXABORT:
			tcflow(fd_com, TCOOFF);
			break;
		case COMM_PURGE_RXABORT:
			tcflow(fd_com, TCIOFF);
			break;
		case COMM_PURGE_TXCLEAR:
			tcflush(fd_com, TCOFLUSH);
			break;
		case COMM_PURGE_RXCLEAR:
			tcflush(fd_com, TCIFLUSH);
			break;
		default:
			LIB_PRINT("Unknow flag\n");
			return -1;
	}

	return 0;
}

#define dprintfbin(buf, size) 					\
	do {							\
		int i; 						\
		for (i = 0; i < size - 1; i++){ 		\
			if (0 == i % 16){ 			\
				if (0 != i)			\
					printf("\n");		\
				printf("0x%04x: ", i); 		\
			}					\
			printf("%02x ", ((char*)buf)[i]);	\
		}						\
		printf("%02x\n", ((char*)buf)[i]); 		\
	} while(0)

// ========================================================================

int cnt = 0;
unsigned char cache[16] = "";
void format_show_char(unsigned char byte)
{
	printf("%02x ", byte);
	cache[cnt % 16] = byte;
	cnt++;
	if(0 == cnt % 16) {
		printf(" |  ");
		int ii;
		for(ii = 0; ii < 16; ii ++) {
			printf("%c"
				, isprint(cache[ii])? cache[ii]: '.'
			);
		}

		printf("\n");
	}
	fflush(stdout);
}

int main(int argc, char *argv[])
{
	printf("version: %s %s\n", __DATE__, __TIME__);

	if(1 == argc) {
		printf("usage:\n" \
			"\t%s /dev/ttySP2 115200 test\n" \
			"\t%s /dev/ttySP2 115200 read\n" \
			"\t%s /dev/ttySP2 115200 write 5a a5 04 80 03 00 03\n" \
			"", argv[0], argv[0], argv[0]);
		return -1;
	}

	int fd_com = CommOpen(argv[1]);
	if(fd_com < 0)
		return -1;

	COMM_ATTR attr = {0 };
	//attr.baudrate = 115200;
	attr.baudrate = (DWORD)strtoul(argv[2], NULL, 10);
	attr.databits = 8;			// 8位数据位
	attr.parity = COMM_NOPARITY;		// 无奇偶效验	
	attr.stopbits = COMM_ONESTOPBIT;	// 1位停止位
	if(CommSetAttribute(fd_com, &attr) !=0)
		printf("set com attr failed\n");

	// flush tx, rx
	CommPurge(fd_com, COMM_PURGE_RXCLEAR);
	CommPurge(fd_com, COMM_PURGE_RXCLEAR);

	// 读测试
	if(0 == strcmp(argv[3], "read")){
		//int cnt = 0;
		unsigned char byte;
		printf("now read data from serial......\n");
		while(1) {
			int ret = CommRead(fd_com, &byte, 1);
			if(ret > 0) {
				format_show_char((unsigned char) byte);
			}
		}
	}

	// 写测试
	if(0 == strcmp(argv[3], "write")){
		char *pdata = malloc(1024);
		int num = argc - 4;
		int i;
		int ret;

		for(i = 0; i < num; i++)
			pdata[i] = (char)strtoul(argv[4 + i], NULL, 16);
		dprintfbin(pdata, num);
		ret = CommWrite(fd_com, pdata, num);
		if(ret != num)
		free(pdata);
	}

	// 测试
	if(0 == strcmp(argv[3], "test")){
		while(1) {
			CommWriteHexString(fd_com, "5a a5 05 82 10 20 00 00");
			usleep(1000 * 100 * 3);
			CommWriteHexString(fd_com, "5a a5 05 82 10 20 00 01");
			usleep(1000 * 100 * 3);
		}
	}

	CommDestory(fd_com);
	return 0;
}



