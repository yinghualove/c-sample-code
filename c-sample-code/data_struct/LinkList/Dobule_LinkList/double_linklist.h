#ifndef _DOUBLE_LINKLIST_H_
#define _DOUBLE_LINKLIST_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define ElemType int
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0       // wrong
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出
#define LIST_MAX_SIZE 100 // 线性表最大长度

typedef struct DNode{          //定义双链表结点类型 
    ElemType data;             //数据域
    struct DNode *prior;       //前驱指针
    struct DNode *next;        //后继指针
}DNode, *DLinkList;

DNode *DLinkList_init(DLinkList L);
int DestroyList(DLinkList L);
DLinkList List_TailInsert(DLinkList L);    //正向建立双链表
void PrintList(DLinkList L);
int Length(DLinkList L);
DNode *LocateElem(DLinkList L, int x);
DNode *GetElem(DLinkList L, int i);
DNode *Insert(DLinkList L, DNode *p, int x);
void Delete(DLinkList L, int i);


#endif /*_DOUBLE_LINKLIST_H*/