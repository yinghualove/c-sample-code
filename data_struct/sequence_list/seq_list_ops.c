/*text data struct seqlist*/
#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#include "seq_list_ops.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0       // wrong
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出
#define LIST_MAX_SIZE 100 // 线性表最大长度


/*create a seqlist*/
/*InitList(&L)*/
Status InitList(SeqList *L)
{
    L->elem = (Elemtype *)malloc(sizeof(Elemtype) * LIST_MAX_SIZE); // 分配内存
    if (L->elem == NULL)
        return INFEASIBLE;
    L->length = 0;
    L->listsize = LIST_MAX_SIZE;
    printf("initial finish\n");
    return OK;
}

/*destory a seqlist*/
/*DestoryList(&L)*/
Status DestroyList(SeqList *L)
{
    while (!L->elem)
        free(L->elem);
    L->elem = NULL;
    L->length = 0;
    printf("destory a seqlist finish\n");
    return OK;
}

/*ListEmpty(&L)*/
Status ListEmpty(SeqList *L)
{
    if (L->length == 0)
    {
        printf("ListEmpty\n");
        return OK;
    }
    else
        return INFEASIBLE;
}

/*
向线性表中写数据
WriteList(&L)
*/

Status WriteList(SeqList *L)
{
    printf("线性表的长度：\n");
    scanf("%d", &L->length);
    printf("输入元素：\n");
    for (int i = 0; i < L->length; i++)
    {
        scanf("%d", &L->elem[i]);
        printf("输入的线性表为:elem[%d] = %d\n", i + 1, L->elem[i]);
    }
}
/*ListLength (&L)
初始条件：线性表L已经存在
操作结果：返回表的长度，失败返回-1*/
Status ListLength(SeqList *L)
{

    return L->length;
}

/*Getelem(&L,i,&e)
按位查找
初始条件：线性表L已经存在1=<i<=LIST_SIZE
操作结果：用e返回L中第i个元素的值成功返回0出错返回-1*/
Status Getelem(SeqList *L, int i, Elemtype *e)
{
    if (i < 0 || i > LIST_MAX_SIZE)
    {
        printf("position error\n");
        return -1;
    }
    *e = L->elem[i - 1];
    printf("元素序号为%d的值为:%d\n", i, *e);
    return 0;
}

/*Locateelem(&L,e)
按值查找
初始条件：线性表L已经存在
操作结果：返回L中第一个和e相等的序列号，若元素不存在，则返回-1*/
Status Locateelem(SeqList *L, Elemtype e)
{

    int i; // 遍历整个链表，直到结尾若没找到返回-1
    for (i = 0; i < L->length; i++)
    {
        if (L->elem[i] == e){
            printf("i = %d\n",i+1);
            return (i + 1);
        }
    }
    return -1;
}

/*Priorelem(&L,cur_e,&pre_e)
初始条件：线性表已经存在
操作结果：若cur_e是L中的元素，且不是第一个，则用pre_e返回它的前驱元素，否则返回错误-1，成功返回0*/
Status Priorelem(SeqList *L, Elemtype cur_e, Elemtype *pre_e)
{
    int i = 0;
    if (cur_e == L->elem[0])
        return -1;
    i = Locateelem(L, cur_e);
    if (i == -1)
        return -1;
    else
    {
        *pre_e = L->elem[i - 2];
        return 0;
    }
}

/*Nextelem(&L,cur_e,&next_e)
初始条件：线性表已经存在
操作结果：若cur_e是L中的元素，且不是最后一个，则用next_e返回它的后继元素，否则返回错误-1，成功返回0*/
Status Nextelem(SeqList *L, Elemtype cur_e, Elemtype *next_e)
{
    int i = 0;
    if (cur_e == L->elem[ListLength(L) - 1])
        return -1;
    i = Locateelem(L, cur_e);
    if (i == -1)
        return -1;
    else
    {
        *next_e = L->elem[i];
        return 0;
    }
}

/*ListInsert(&L,i,e)
初始条件：线性表L已经存在
操作结果：在L中第i个位置之前插入新的数据，表长加1，返回0成功，-1错误*/
Status ListInsert(SeqList *L, int i, Elemtype e)
{
    if (i < 1 || i > L->length + 1) // 判断当前i的范围是否有效
        return FALSE;
    if (L->length >= L->listsize) // 判断存储空间是否已满，不能插入
        return FALSE;
    for (int j = L->length; j >= i; j--) // 将第i个元素及之后的元素右移
        L->elem[j] = L->elem[j - 1];
    L->elem[i - 1] = e; // 在位置i出放入e
    L->length++;        // 长度加1
    printf("增加的第%d个值为%d\n", i, e);
    for (i = 0; i < L->length; i++)
    {
        printf("增加后的顺序表为:elem[%d]=%d\n", i + 1, L->elem[i]);
    }
    return TRUE;
}

/*Listdelete(&L,i,&e)
初始条件：线性表L存在
操作结果：删除L中序号为i的元素，并将其值由e带回,成功返回0，出错返回-1*/
Status Listdelete(SeqList *L, int i, Elemtype *e)
{

    if (i < 1 || i > L->listsize)
    {
        printf("postion error:\n");
        return -1;
    }
    Elemtype *q = NULL;
    Elemtype *p = NULL;
    q = &L->elem[i - 1]; // 删除元素位置
    *e = *q;
    p = &L->elem[L->length - 1]; // 表尾位置
    while (q <= p)
    {
        *q = *(q + 1);
        q++;
    }
    L->length--;
    for(i = 0;i<L->length;i++)
        printf("删除后的顺序表elem[%i] = %d\n",i+1,L->elem[i]);
    return 0;
}

