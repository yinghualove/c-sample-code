#include <stdio.h>
#include "link_list.h"

int main(int argc,char **argv)
{

    LinkList L;
    LNode *S,*ret;
    int sn;                   //serial number
    int value;                //结点值
    S = List_HeadInsert(L);   //逆向建立单链表
    print(S);
    printf("按位查找\n");
    printf("输入查找的结点：\n");
    scanf("%d",&sn);
    ret = GetElem(S,sn);
    printf("ret->data=%d\n",ret->data);

    printf("按值查找\n");
    printf("输入结点值：\n");
    scanf("%d",&value);
    ret = LocateElem(S,value);
    printf("ret->sn=%d\n",ret->sn);

    printf("插入结点\n");
    printf("输入插入的结点序列号和结点值:\n");
    scanf("%d%d",&sn,&value);
    ret = ListInsert(S,sn,value);
    print(ret);

    DestroyList(S);
    printf("main end\n");
    // S = List_TailInsert(L);   //正向建立单链表
    // print(S);
    //DestroyList(L);

    return 0;
}