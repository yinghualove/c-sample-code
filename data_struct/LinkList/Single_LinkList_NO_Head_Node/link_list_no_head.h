#ifndef _LINK_LIST_NO_HEAD_H_
#define _LINK_LIST_NO_HEAD_H_
#include <stdio.h>
typedef int ElemType;

typedef struct LNode{    //定义单链表节点类型
    ElemType data;       //数据域
    struct LNode *next;  //指针域
    ElemType sn;         //序号
}LNode;

typedef struct LinkList{
    LNode *head;
}Link_List , *LinkList;


LNode *InitList(LNode *L);
LNode *List_HeadInsert(LNode *L);   //逆向建立单链表
LNode *List_TailInsert(LNode *L,ElemType x);   //正向建立单链表
int DestroyList(LNode *L);
LNode *GetElem(LNode *L,int i);
LNode *LocateElem(LNode *L,ElemType e);
LNode *List_BehindInsert(LNode *L,int i,ElemType e);  
LNode *List_DeleteNode(LNode *L,int i);
void print(LNode *L);



#endif /*_LINK_LIST_NO_HEAD_H*/