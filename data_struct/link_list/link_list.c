#include <stdio.h>
#include "link_list.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0       // wrong
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出
#define LIST_MAX_SIZE 100 // 线性表最大长度

LinkList List_HeadiNSERT(LinkList *L){   //逆向建立单链表
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));  //创建头结点
    

}