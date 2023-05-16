#include "seq_stack.h"

int main(int argc,char **argv)
{
    SeqStack S;
    ElemType e;
    ElemType x;
    //InitStack(S);
    printf("输入入栈的数：\n");
    scanf("%d",&e);       
    Push(&S,e);
    printf("入栈的数为：%d\n",S.data[S.top]);

    Pop(&S,&x);
    printf("出栈数为%d\n",x);

    return 0;
}