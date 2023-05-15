#include "double_linklist.h"


int main(int argc,char **argv)
{
    DLinkList L,S;
    ElemType x;
    int i;
    DLinkList p;
    DLinkList_init(L);
    L = List_TailInsert(L);

    PrintList(L);

    printf("length = %d\n",Length(L));
    
    printf("输入需要查找的值\n");
    scanf("%d",&x);
    p = LocateElem(L,x);
    printf("p->data = %d\n",p->data);
    
    printf("输入需要查找的序号\n");
    scanf("%d",&i);
    p = GetElem(L,i);
    printf("p->data = %d\n",p->data);

    
    printf("输入需要插入的序号和值\n");
    scanf("%d",&i);
    scanf("%d",&x);
    p = GetElem(L,i-1);
    Insert(L,p,x);
    PrintList(L);

    printf("输入需要删除的序号\n");
    scanf("%d",&i);
    Delete(L,i);

    PrintList(L);

    DestroyList(L);

    return 0;
}