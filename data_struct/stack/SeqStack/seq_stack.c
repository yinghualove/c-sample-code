/*
    *栈的顺序储存操作
*/

#include "seq_stack.h"

/*
    *初始化栈
*/
Status InitStack(SeqStack *S)
{
    S->top = -1;
    printf("initial finish\n");
    return OK;
}

/*
    *入栈
    *插入元素e为新的栈顶元素
    *时间复杂度O（1）
*/
Status Push(SeqStack *S,ElemType e)
{
    if(S->top == MAXSIZE -1)   //栈满
    {
        return ERROR;
    }
    S->top++;                 //栈顶指针加一
    S->data[S->top] = e;      //将新插入元素赋值给栈顶空间
    S->length++;              //栈长度加1
    return OK;
}

/*
    *遍历栈
*/
void Ergodic_Elem(SeqStack *S)
{
    while(S->top != -1)
    {
        printf("%d ",S->data[S->top--]);
    }
    printf("\n");
}

/*
    *出栈
    *若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，负责返回ERROR
    *时间复杂度O（1）
*/
Status Pop(SeqStack *S,ElemType *e)
{
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];       //将要删除的栈顶元素赋值给e
    S->top--;                   //栈顶指针-1
    return OK;
}

/*
    *判空
*/
Status EmptyStack(SeqStack *S)
{
    if(S->top=-1)
        printf("栈已空\n");
    else 
        printf("当前栈不为空\n");
    return OK;
}

/*
    *销毁栈
*/
Status DestoryStack(SeqStack *S)
{
    S->top = -1;
    return OK;
}