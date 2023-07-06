#include "double_linklist.h"

//初始化双链表
DNode *DLinkList_init(DLinkList L)
{
    L = (DLinkList)malloc(sizeof(DNode));      //创建头结点
    L->next = NULL;                            //初始化
    L->prior = NULL;                           //初始化
    printf("DLinkList init finished !\n");
    return L;
}


//尾插法建立双链表
DLinkList List_TailInsert(DLinkList L)    //正向建立双链表
{   
    ElemType x;                                //设立元素类型为整型
    L = (DLinkList)malloc(sizeof(DNode));  //创建头结点
    DNode *s,*r=L;                        //r为表尾指针
    printf("input data:\n");
    scanf("%d",&x);                       //输入结点值
    while (x!=9999)                       //输入9999表示结束
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = NULL;
        s->prior = r;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    //r->next = L;
    //L->prior = r;
    printf("---------------------\n");
    return L;
}

/*destory a double link list*/
/*DestoryList(&L)*/
int DestroyList(DLinkList L)
{
    DLinkList p,q;
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

//遍历操作
void PrintList(DLinkList L)
{
    DNode *p = L->next;
    while(p)
    {
        printf("data = %d\n",p->data);
        p = p->next;
    }
}

//求双链表的长度
int Length(DLinkList L)
{
    DNode *p = L->next;
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

//按值查找：查找x在L中的位置
DNode *LocateElem(DLinkList L, ElemType x)
{
    DNode *p = L->next;
    while(p && p->data != x)
    {
        p = p->next;
    }
    return p;
}

//按位查找：查找在双链表L中第i个位置的结点
DNode *GetElem(DLinkList L, int i)
{
    int j=1;
    DNode *p = L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}



//将x插入到双链表L中*p结点的下一个结点
DNode *Insert(DLinkList L, DNode *p, ElemType x)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = x;
    s->next = p->next;  //把p->next赋值给s的后继
    p->next->prior = s; //把s赋值给p->next的前驱
    s->prior = p;  //把p赋值给s的前驱
    p->next = s; //把s赋值给p的后继
    return p;
}

//删除操作:将双链表中的第i个结点删除
void Delete(DLinkList L, int i)
{
    if(i<1 || i>Length(L))
    {
        printf("delete failed: index is wrong.\n");
        return;
    }
    DNode *p = GetElem(L,i-1);
    DNode *q = p->next;
    p->next = q->next; //1
    q->next->prior = p; //2
    free(q);
}



