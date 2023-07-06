/*
    *习题1：设计一个递归算法，删除不带头结点的单链表L中所有的值为x的结点
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define ERROR -1
#define OK 0
#define MAX_LEN 100
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node,*LNode;

typedef struct LinkList{
    Node *head;
}LinkList;

Node *CreateNode(ElemType x)
{
    LNode s;
    s = (LNode)malloc(sizeof(Node));
    s->data = x;
    s->next = NULL;
}

void PrintList(LinkList *L)
{
    
}

LinkList *InitLinkList(LinkList *L)
{
    L->head = NULL;
    return L;
}

LinkList *Insert(LinkList *L)
{
    
}



void DelLinkList(LinkList *L)
{
    LinkList *p,*q;
    //p = L;
    if(L==NULL)
        return;
    if(L->data == 9)
    {
        q = L;
        L = L->next;
        free(q);
        DelLinkList(L);
    }
    else 
    {
        DelLinkList(L->next);
    }
}

int main(int argc,char **argv)
{
    LinkList *L,*S;
    S = InitLinkList(L);
    //PrintList(S);
    //DelLinkList(S);

    return 0;
}