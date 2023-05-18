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

//遍历栈元素
void Ergodic_Elem(LinkStack *S)
{
    LinkStack *p;
    p = S;
    while(p->count != 0)
    {
        printf("入栈数：%d\n",p->top->data);
        p->top = p->top->next;
        p->count--;
    }
}

/*
    *出栈
    *若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，负责返回ERROR
    *时间复杂度O（1）
*/
Status Pop(LinkStack *S,ElemType *e)
{
    LinkStackPtr p;
    if(!S->top->data)
        return ERROR;
    *e=S->top->data;
    p=S->top;                   //将栈顶结点赋值给p
 //   while(S->top->data)
   // {
//        p=S->top;                   //将栈顶结点赋值给p
        S->top=S->top->next;        //使得栈顶指针下移一位，指向后一结点
        free(p);                    //释放结点p
        S->count--;
   // }
    return OK;
}