#ifndef _LINK_LIST_H
#define _LINK_LIST_H

typedef struct LNode{   //定义单链表节点类型
    ElemType *data;     //数据域
    struct LNode *next;  //指针域
}LNode, *LinkList;


#endif /*_LINK_LIST_H*/