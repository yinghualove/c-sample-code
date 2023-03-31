/*自动获取网卡名字*/
/*
Linux网卡命名规则：
    en代表Ethernet
    wl代表无线网卡（WIFI）
    ww代表无线广域网卡（4G上网卡等）
    eno中的o代表Onboard，即板载的意思，eno0这样的为板载网卡
    ens代表可热插拔的网卡
    enp中的p代表pci，也就是pcie网卡
    enx/wlx是使用MAC地址命名的网卡

*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX_PATH_LEN 20

char *resultbuf;

int get_nw_card_name(){
    resultbuf = (char *)malloc(sizeof(MAX_PATH_LEN));
    //char resultbuf[MAX_PATH_LEN];
    char namebuf[30];
    //bzero(resultbuf, MAX_PATH_LEN);
    int result;
    FILE *fp; 
    fp = popen("cat /proc/net/dev | grep \":\" | grep -v 'lo\\|sit0' | cut -d ':' -f1 | sed -e 's/^[ \t]*//g'","r");
     if(fp == NULL){
        goto error_close;
    }
    //处理数据行
    while(fgets(resultbuf,MAX_PATH_LEN,fp) != NULL){
        //bzero(namebuf, sizeof(namebuf));
        //sscanf(resultbuf, "%s\n", namebuf);
        result = strncmp("wwp0s",resultbuf,4);
        if(result == 0){
            printf("neme = %s\n",resultbuf);
            break;
        }
    }
    pclose(fp);
    return 0;

error_close:

    return -1;

}

int main(int agrc,char **agrv){
    char *buff;
    int ret;
    buff = (char *)malloc(sizeof(MAX_PATH_LEN));
    //bzero(buff, MAX_PATH_LEN);
    ret = get_nw_card_name();
    printf("ret = %d\n",ret);
    printf("buff = %s\n",resultbuf);
    resultbuf[strlen(resultbuf)-1] = '\0';
    printf("resultbuf = %s\n",resultbuf);

    free(resultbuf);
    return 0;
}