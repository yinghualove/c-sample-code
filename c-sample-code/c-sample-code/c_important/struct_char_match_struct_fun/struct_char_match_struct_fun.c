/*
根据结构体输入的字符或数字匹配结构体的函数
*/

#include <stdio.h>
#include <string.h>

typedef struct L{
    char *node;
    void (*fun)(int argc,char **argv);
}L_node;

void *fun1(int argc,char **argv){
    printf("fun1()\n");
}

void *fun2(int argc,char **argv){
    printf("fun2()\n");
}

void (*handle)( int argc,char **argv)=NULL;

L_node L_sample[]={
    {"a",fun1},
    {"b",fun2},
};



void array_match(int argc,char **argv){
    for(int i=0;i<2;i++){
    if(strncmp(argv[1],L_sample[i].node,1)==0){
        handle = L_sample[i].fun;   //将sample里面的函数赋给handle
        handle(argc,argv);       //handle执行的sample对应函数
    }
    // if(L_sample[i].fun)
    //     handle(argc,argv);
    }
}

int main(int argc,char **argv){

    array_match(argc,argv);

    return 0;
}