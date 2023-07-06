#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include <stdio.h>
typedef int ElemType;

typedef struct LNode{    //定义单链表节点类型
    ElemType data;       //数据域
    struct LNode *next;  //指针域
    ElemType sn;         //序号
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList L);   //逆向建立单链表
LinkList List_TailInsert(LinkList L);   //正向建立单链表
int DestroyList(LinkList L);
LNode *GetElem(LinkList L,int i);
LNode *LocateElem(LinkList L,ElemType e);
LNode *List_BehindInsert(LinkList L,int i,ElemType e);  
LNode *List_DeleteNode(LinkList L,int i);
void print(LinkList L);



#endif /*_LINK_LIST_H*/