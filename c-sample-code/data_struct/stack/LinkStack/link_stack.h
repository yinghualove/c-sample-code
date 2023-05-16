#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR -1
#define OK 0

typedef int Status;
typedef int ElemType;

typedef struct  StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;


Status Push(LinkStack *S, ElemType e);
Status Pop(LinkStack *S,ElemType *e);

#endif /* _LINK_STACK_H */