#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int n=9;  

pthread_t tid1;

void *fun1(char *str)
{
    while(n)
    {
        printf("pthread TID=%ld  n=%d\n",pthread_self(),n);
        printf("%s\n",str);
        n--;  //打印n后，n减1
        sleep(1);
    }
    printf("child pthread_exit success\n"); //线程退出并返回这个信息
    pthread_exit(NULL);
    //pthread_detach(tid1); 

}
int main(int argc, char *argv[])
{
    //pthread_t tid1;
    int ret;
    char *str = "abc";
    ret=pthread_create(&tid1,NULL,fun1,str);
    if (0 != ret)
    {
        perror("pthread_create fail");
        return -1;
    }
    void *p=NULL;
    //pthread_join(tid1,&p);
    pthread_detach(tid1); 
    printf("pthread exit success\n");
    while(n)
    {
        printf("main n=%d\n",n);
        n--;  //打印n后，n减1
        sleep(1);
    }
    //printf("%s\n",(char *)p);
    return 0;
} 