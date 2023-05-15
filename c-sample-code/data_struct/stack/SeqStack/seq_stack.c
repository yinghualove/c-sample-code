#include "seq_stack.h"

/*create a seqstack*/
/*InitStack(S)*/
Status InitStack(SeqStack *S)
{
    S->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE); // 分配内存
    if (!S->data)                                            //异常处理，分配成功时S为空栈，分配失败时，返回ERROR
        return ERROR;
    S->length = 0;                                                  //初始化栈长度
    S->stacksize = MAXSIZE;                                    //定义栈最大长度
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
    *出栈
    *若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，负责返回ERROR
    *时间复杂度O（1）
*/
Status Pop(SeqStack *S,ElemType *e)
{

}