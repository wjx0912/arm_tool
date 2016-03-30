编译方法：

修改Makefile里面的CROSS变量（第十行附近）

原理：

arm使用统一地址空间，通过mmap系统调用在进程内mm table增加address map