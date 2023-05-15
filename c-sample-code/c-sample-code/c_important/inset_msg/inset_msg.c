#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 #define OK 1;

char buf[50][300];
 
int main()
{
    int i;
    char *dns0="nameserver 120.196.165.7\n";						//要插入的数据
    char *dns1="nameserver 221.179.38.7\n";
    char *edns = "options edns0\n";
    int j;

    FILE *fp = fopen("/etc/resolv.conf", "r");		//读方式打开文件
    for(i=0;i<50;i++)
    {
        fgets(buf[i], 50, fp);
        if(strncmp(buf[i],dns0,25)==0){
            printf("dns0 = %s\n",buf[i]);
            printf("File already have dns,don't set again\n");
            return OK;
        }
        else if(strncmp(buf[i],dns1,25)==0){
            printf("File already have dns,don't set again\n");
            return OK;
        }
        else if(strncmp(buf[i],edns,13)==0){
            printf("The dns is configured for the first time\n");
            j = i;        
            break;
        }
    }
    fclose(fp);								//关闭文件
    
    // for(i = 1; i<7; i ++)					//删除第2行
    // {   
    //     strcpy(buf[i],buf[i+1]);
    // }
        
    strcpy(buf[j+1], dns0);					//插入到第19行。
    strcpy(buf[j+2], dns1);					//插入到第20行。
    fp=fopen("/etc/resolv.conf", "w"); 				//写方式打开文件。
    for(i = 0; i < 50; i ++)				//写入所有处理后的数据
    {
        fputs(buf[i],fp);
        //printf("buf[%d] = %s\n",i,buf[i]);
        for(j;j<30;j++)
            printf("buf[%d] = %s\n",j,buf[j]);
    }			
  
    fclose(fp);//关闭文件。
    return 0;    
}