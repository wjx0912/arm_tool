以下2个版本是匹配的（官网推荐），其它版本懒得测试了，附件有一份已经编译好的tcpdump（静态链接）

cd libpcap-1.7.4

	CC=arm-linux-gnueabihf-gcc ./configure --host=arm-linux --with-pcap=linux
	make CFLAGS+="-static" V=1

cd tcpdump-4.7.4

	CC=arm-linux-gnueabihf-gcc ./configure --host=arm-linux LDFLAGS=-L/home/wyt/source/tcpdump/libpcap-1.7.4
	make CFLAGS+="-static" V=1

常用指令

	tcpdump
	tcpdump -i eth0
	tcpdump tcp port 12345
	tcpdump udp port 54321
	tcpdump -x
	tcpdump ip host 192.168.1.23
