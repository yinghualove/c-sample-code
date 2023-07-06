/*
    *单链表操作集合

*/

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
    LinkList p,q;
    p = L->next;                            //第1个结点指针赋给p
    while(p)                                //没到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;                        //头结点指针域为空
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
    if(!p || j>i)                   //第i个元素不存在
        return ERROR;
    return p;                       //返回第i个结点的指针，若i大小表长，则返回NULL
}

//功能：按值查找
//结果：返回输入值的结点指针
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p=L->next;                     //第1个结点指针赋给p
    int sn=1;
    p->sn = sn;                           //第一个结点指针的结点值
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
        //++sn;
        p->sn = sn+1;
    }
    return p;
}


//结果：在第i个位置插入新的结点（后插）
//时间复杂度：O(n)
LNode *List_BehindInsert(LinkList L,int i,ElemType e)
{
    LNode *p,*s;
    s=(LNode*)malloc(sizeof(LNode));  //创建新结点
    s->data = e;
    p = GetElem(L,i-1);            //查找插入位置的前驱结点
    /*
        *必须先执行s->next=p->next,在执行p->next=s.两者不能颠倒
    */
    s->next=p->next;               //新结点s指针域指向p的后继结点
    p->next=s;                     //p的指针域指向新插入的结点s

    return p;
}



//结果：删除第i个位置的结点
LNode *List_DeleteNode(LinkList L,int i)
{
    LNode *p,*q;
    p = GetElem(L,i-1);              //查找删除位置的前驱结点
    q = p->next;                    //令q指向被删除将诶殿
    p->next=q->next;                //将*q结点从链中断开
    free(q);                        //释放结点的存储空间

    return p;
}
