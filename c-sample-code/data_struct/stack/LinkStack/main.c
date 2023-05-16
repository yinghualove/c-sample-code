#include "link_stack.h"

int main(int argc,char **argv)
{
    LinkStack S;
    ElemType e;
    ElemType x;

    printf("输入入栈数：\n");
    scanf("%d",&e);
    S.count=0;
    while(e!=9999)
    {
        Push(&S,e);
        printf("入栈数：%d\n",S.top->data);
        scanf("%d",&e);
    }
    printf("count=%d\n",S.count);

    Pop(&S,&x);
    printf("出栈数：%d\n",x);
}