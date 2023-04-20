#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *at_thread(){
    open_at_port();
    init_at_port();
    send_at_command();
    receive_at_command();
    close_at_port();
}

int create_at_thread(int argc,char **argv)
{
    pthread_t at_cid;
    pthread_create(&at_cid,NULL,at_thread,NULL);
    void *p=NULL;
    pthread_join(at_cid,&p);
}