#include <stdio.h>
#include "seq_list_ops.h"

int main()
{
    SeqList L;
    Elemtype e,elem,value;

    printf("---------------------------------\n");
    InitList(&L);
    printf("create a seqlist finish\n");
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    ListEmpty(&L);
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("写入数据到链表中\n");
    WriteList(&L);
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("list length:%d\n", ListLength(&L));
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("按位查找\n");
    printf("输入元素序号:\n");
    scanf("%d", &elem);
    Getelem(&L, elem, &e);
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("按值查找\n");
    printf("输入需要查找的元素值：\n");
    scanf("%d",&value);
    printf("%d的元素序号为:%d\n",value,Locateelem(&L,value));
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("插入操作\n");
    printf("输入需要插入的元素序号和元素值：\n");
    scanf("%d%d",&elem,&value);
    ListInsert(&L,elem,value);
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    printf("删除操作\n");
    printf("输入需要删除的元素序号：\n");
    scanf("%d",&elem);
    Listdelete(&L,elem,&value);
    printf("---------------------------------\n");

    printf("---------------------------------\n");
    DestroyList(&L);
    printf("---------------------------------\n");
   
    return 0;
}