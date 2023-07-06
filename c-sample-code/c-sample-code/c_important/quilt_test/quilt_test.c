#include <stdio.h>

/*
quilt use asmple
usage:
install quilt:sudo apt-get install quilt
quilt new命令创建初始补丁文件 :quilt new add.patch
quilt add命令添加目标文件: quilt add quilt_test.c
vi/vim修改代码:vi quilt_test.c
quilt diff查看修改的代码:quilt quilt_test.c
quilt refresh命令生成补丁文件:quilt refresh
*/

int main(int argc,char **argv){
    printf("hello\n");
	printf("add\n");

    return 0;
}
