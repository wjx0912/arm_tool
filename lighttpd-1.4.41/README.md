	1.下载最新版本lighttpd-1.4.41
	https://github.com/lighttpd/lighttpd1.4
	
	2.编译
	运行autogen.sh
	运行1.sh
	运行sudo make install
	
	3.编辑
	doc/config/lighttpd.conf
	doc/config/modules.conf
	
	4.需要的文件
	把/opt/lighttpd-1.4.41-arm/拷贝到开发板的/opt/
	把src下的lighttpd和lighttpd-angel拷贝到开发板的/opt/
	
	5.把doc/config/拷贝到/etc/lighttpd
	
	6.发现lightppd运行不起来，查找原因：
	arm-none-linux-gnueabi-objdump -p lighttpd
	arm-none-linux-gnueabi-nm  lighttpd | grep 2.17
	修改src/log.c  把clock_gettime这行直接返回0，make clean重新编译
	
	7.开机脚本加：
	mkdir -p /var/tmp
	mkdir -p /var/log/lighttpd
	/opt/lighttpd -f /etc/lighttpd/lighttpd.conf     #如果加-D参数会前台运行
