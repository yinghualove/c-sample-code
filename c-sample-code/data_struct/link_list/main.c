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
    printf("输入查找的结点：\n");
    scanf("%d",&sn);
    ret = GetElem(S,sn);
    printf("ret->data=%d\n",ret->data);

    printf("输入结点值：\n");
    scanf("%d",&value);
    ret = LocateElem(L,value);
    printf("ret->id=%d\n",ret);

    DestroyList(S);
    // S = List_TailInsert(L);   //逆向建立单链表
    // print(S);
    //DestroyList(L);

    return 0;
}