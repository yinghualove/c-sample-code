/*
    *没有头结点的单链表操作集合

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "link_list_no_head.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0       // wrong
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出
#define LIST_MAX_SIZE 100 // 线性表最大长度

//创建结点
LNode *create_node(ElemType x)
{
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    return s;
}

//遍历链表
void print(LNode *L)
{
    LNode *cur;
    cur = L;
    while(cur != NULL)
    {
        printf("cur->%d\n",cur->data);
        cur = cur->next;
    }
}

//线性表初始化
LNode *InitList(LNode *L)
{
    return NULL;
}

//头插法建立单链表
LNode *List_HeadInsert(LNode *L)   //逆向建立单链表
{

}

//尾插法建立单链表
LNode *List_TailInsert(LNode *L,ElemType x)   //正向建立单链表
{
    LNode *cur;
   //首先判断头结点是否为空
   if(L == NULL)
        //创建一个头结点
        L = create_node(x);
    else   //头结点不为空
        cur = L;
        while (cur->next != NULL)    //找到链表尾结点
        {
            cur = cur->next;
        }
        cur->next = create_node(x);   //在尾结点后面新增一个结点
    return L;     
}

/*destory a seqlist*/
/*DestoryList(L)*/
int DestroyList(LNode *L)
{
    LNode *p;
    while(L)
    {
        p = L;
        L = p->next;
        free(p);
    }
    L = NULL;
}

//功能：按序号查找结点值
//结果：返回序号i的结点值,返回第i个结点的指针
LNode *GetElem(LNode *L,int i)
{
   ElemType val;
   LNode *cur;
   cur = L;
   while(cur)
   {
        
   }
}

//功能：按值查找
//结果：返回输入值的结点指针
LNode *LocateElem(LNode *L,ElemType e)
{
   
}


//结果：在第i个位置插入新的结点（后插）
//时间复杂度：O(n)
LNode *List_BehindInsert(LNode *L,int i,ElemType e)
{
    
}



//结果：删除第i个位置的结点
LNode *List_DeleteNode(LNode *L,int i)
{
    
}
