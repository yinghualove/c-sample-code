#include "link_stack.h"

//插入新的元素e为新的栈顶元素
Status Push(LinkStack *S, ElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;     //将当前的栈顶元素赋值给新的结点的直接后继
    S->top=s;           //将新的结点s赋值给栈顶指针
    S->count++;
    return OK;
}

/*
    *出栈
    *若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，负责返回ERROR
    *时间复杂度O（1）
*/
Status Pop(LinkStack *S,ElemType *e)
{
    LinkStackPtr p;
    int x;
    if(!S->top->data)
        return ERROR;
    printf("aaaaaaaaaaaa\n");
    printf("data=%d\n",S->top->data);
    x=S->top->data;
    printf("x=%d\n",x);
    *e = x;
    printf("bbbbbbbbbbbbbbbb\n");
    p=S->top;
    printf("ccccccccccccccc\n");
    S->top=S->top->next;
    free(p);
    S->count--;
    return OK;
}