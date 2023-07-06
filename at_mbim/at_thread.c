#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/select.h>
#include "cmd_match.h"
#include "at_procs.h"


int g_stop = 0;

void sig_handler(int sig_num)
{
    if(sig_num == SIGINT)
        g_stop = 1;
}


void adjust_buf(char *buf)
{
    int i = strlen(buf);
    strcpy(&buf[i-1],"\r");
}

void *at_thread(void *data){

    Serial_Attr *attr = data;
    int              retval;
    char             sbuf[128] = {0};
    char             rbuf[128] = {0};
    fd_set           rset;

    if(SerialPort_Open(attr) != 0)
    {
        printf("Open %s failed!\n",attr->SerialName);
        return NULL;
    }

    if(SerialPort_init(attr) < 0)
        goto cleanup;

    signal(SIGINT,sig_handler);
    
    fflush(stdin);
    printf("Start to communicate with com port......\n");

    while(!g_stop)
    {
        FD_ZERO(&rset);
        FD_SET(STDIN_FILENO,&rset);
        FD_SET(attr->fd,&rset);

        /*  使用多路复用监听标准输入和串口fd */
        retval = select(attr->fd + 1,&rset,NULL,NULL,NULL);
        if(retval < 0)
        {
            printf("Program exit......\n");
            break;
        }

        if(retval == 0)
        {
            printf("Time Out.\n");
            goto cleanup;
        }

        if(FD_ISSET(STDIN_FILENO,&rset))
        {
            memset(sbuf,0,sizeof(sbuf));

            /* 从标准输入读取命令 */
            fgets(sbuf,sizeof(sbuf),stdin);
            /* 处理要发送的数据 */  
            adjust_buf(sbuf);
            
            if(SerialPort_send(attr,sbuf,strlen(sbuf)) < 0)
            {
                printf("Write failed.\n");
                goto cleanup;
            }
            printf("send success\n");
            fflush(stdin);

        }

        if(FD_ISSET(attr->fd,&rset))
        {
            memset(rbuf,0,sizeof(rbuf));
            printf("now read msg\n");
            retval = SerialPort_recv(attr,rbuf,sizeof(rbuf),0);
            if(retval <= 0)
            {
                printf("Read failed:%s\n",strerror(errno));
                break;
            }

            printf("%s",rbuf);
            fflush(stdout);
        }

        
    }


    SerialPort_Close(attr);
    pthread_exit(NULL);

cleanup:
    SerialPort_Close(attr);
    pthread_exit(NULL);
    return NULL;
}

int create_at_thread(Serial_Attr *attr)
{
    pthread_t at_cid;
    pthread_create(&at_cid,NULL,(void *)at_thread,attr);
    void *p=NULL;
    pthread_join(at_cid,&p);
    free(attr);
}