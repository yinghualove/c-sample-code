#ifndef _SEQ_STACK_H
#define _SEQ_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR -1
#define OK 0

typedef int Status;
typedef int ElemType;

typedef struct SqStack{
    ElemType *data;       //数据域
    int top;              //栈顶指针
    int length;           //栈长度
    int stacksize;         //栈总大小
}SeqStack;

#endif /* _SEQ_STACK_H */
