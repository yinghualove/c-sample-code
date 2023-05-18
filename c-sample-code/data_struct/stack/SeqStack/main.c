#include "seq_stack.h"

int main(int argc,char **argv)
{
    SeqStack *S;
    ElemType e;
    ElemType x;
    InitStack(S);
    printf("输入入栈的数：\n");
    scanf("%d",&e);
    while(e != 9999)
    {       
        Push(S,e);
        printf("%d入栈\n",S->data[S->top]);
        scanf("%d",&e);
    }
    printf("出栈顺序：\n");
    Ergodic_Elem(S);

    while(S->top != -1)
    {
        Pop(S,&x);
        printf("%d出栈\n",x);
    }

    EmptyStack(S);

    DestoryStack(S);

    return 0;
}