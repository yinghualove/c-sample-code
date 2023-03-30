#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "link_list.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0       // wrong
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出
#define LIST_MAX_SIZE 100 // 线性表最大长度

void print(LinkList L){
    LNode *s;
    s=L->next;
    do{
        printf("data:%d\n",s->data);
        s=s->next;
    }while (s!=NULL);
    
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList L){   //逆向建立单链表
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));  //创建头结点
    L->next=NULL;                         //初始化为空链表
    printf("input data:\n");
    scanf("%d",&x);                       //输入结点值
    while (x!=9999)                       //输入9999表示结束
    {
        s=(LNode*)malloc(sizeof(LNode));  //创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;                        //将新结点插入表中，L为头指针
        scanf("%d",&x);
    }

    printf("---------------------\n");
    return L;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList L){   //正向建立单链表
    int x;                                //设立元素类型为整型
    L = (LinkList)malloc(sizeof(LNode));  //创建头结点
    LNode *s,*r=L;                        //r为表尾指针
    printf("input data:\n");
    scanf("%d",&x);                       //输入结点值
    while (x!=9999)                       //输入9999表示结束
    {
        s=(LNode*)malloc(sizeof(LNode));  //创建新结点
        s->data=x;
        r->next=s;
        r=s;                        //r指向新的表尾结点
        scanf("%d",&x);
    }
    r->next=NULL;
    printf("---------------------\n");
    return L;
}

/*destory a seqlist*/
/*DestoryList(&L)*/
int DestroyList(LinkList L)
{
    while (!L)
        free(L);
    L=NULL;
    printf("destory a linklist finish\n");
    return OK;
}

//功能：按序号查找结点值
//结果：返回序号i的结点值,返回第i个结点的指针
LNode *GetElem(LinkList L,int i)
{
    int j=1;                        //计数，初始为1
    LNode *p = L->next;             //第1个结点指针赋给p
    if(i==0)
        return L;                   //若i=0，则返回头结点
    if(i<1)
        return NULL;                //若i无效，则返回NULL
    while (p&&j<i)                  //从第1个结点开始找，查找第i个结点
    {
        p=p->next;
        j++;
    }
    return p;                       //返回第i个结点的指针，若i大小表长，则返回NULL
}
