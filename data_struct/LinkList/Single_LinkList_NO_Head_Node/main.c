#include <stdio.h>
#include "link_list_no_head.h"

int main(int argc,char **argv)
{

    LNode *L;
    LNode *ret;
    ElemType x;
    int sn;                   //serial number
    int value;                //结点值
    x = 5;
    printf("start\n");
    L = InitList(L);
    printf("init success\n");
    L = List_TailInsert(L,1);   //正向建立单链表
    L = List_TailInsert(L,2);
    L = List_TailInsert(L,3);
    print(L);
    // print(S);
    // printf("输入查找的结点：\n");
    // scanf("%d",&sn);
    // ret = GetElem(S,sn);
    // printf("ret->data=%d\n",ret->data);

    // printf("输入结点值：\n");
    // scanf("%d",&value);
    // ret = LocateElem(S,value);
    // printf("ret->sn=%d\n",ret->sn);


    // printf("插入结点：前插操作\n");
    // printf("输入插入的结点和结点值\n");
    // scanf("%d%d",&sn,&value);
    // ret = List_BehindInsert(S,sn,value);
    // printf("输出整个单链表\n");
    // print(S);


    // printf("删除结点操作\n");
    // printf("输入需要删除的结点:\n");
    // scanf("%d",&sn);
    // ret = List_DeleteNode(S,sn);
    // printf("输出整个单链表\n");
    // print(S);


    // DestroyList(S);
    // S = List_TailInsert(L);   //正向建立单链表
    // print(S);
    //DestroyList(L);

    return 0;
}