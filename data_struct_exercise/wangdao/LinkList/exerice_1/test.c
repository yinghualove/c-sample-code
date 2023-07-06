#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SL;

//增容
struct SListNode* SListBuyNode(DataType x)
{
	//创建一个节点
	struct SListNode* newnode = (struct SListNode*)malloc(sizeof(struct SListNode));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
}
 
//打印
void SListprint(SL* phead)
{
	SL* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
 
//单链表尾插
void SListPushBack(SL** phead,DataType x)
{
	assert(phead);//检查头指针的地址是否为空
	//如果头指针为空，那么就新建一个节点
	struct SListNode* newnode = SListBuyNode(x);
	//如果头指针指向NULL的情况
	if(*phead == NULL)
	{
		//进行增容
		*phead = newnode;
	}
	//如果头指针不指向NULL的情况
	else
	{
		//寻找到尾部,再尾部将值插入
		SL* cur = *phead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		//将新建节点链接到尾节点后面
		cur->next = SListBuyNode(x);
	}
}
//单链表头插
void SListPushFront(SL** phead, DataType x)
{
	assert(phead);
	//如果头指针指向NULL或者不为NULL都可以
	struct SListNode* cur = *phead;
	//创建一个节点
	struct SListNode* newnode = SListBuyNode(x);
	newnode->next = cur;
	*phead = newnode;
}
//单链表尾删
void SListPopBack(SL** phead)
{
	//如果头指针指向NULL
	assert(*phead);
 
	//如果只有一个节点的问题,尾删
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else//多个节点的情况
	{
		//寻找尾的前一个和尾
		struct SListNode* tail = *phead;
		struct SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}
}
//单链表头删
void SListPopFront(SL** phead)
{
	assert(phead);
	//如果头指针指向NULL
	assert(*phead);
	//如果只有一个节点和多个节点的情况
	SL* cur = *phead;
	*phead = cur->next;
	free(cur);
	cur = NULL;
}
//单链表的查找
SL* SListFind(SL* phead,DataType x)
{
	SL* tail = phead;
	//从头找到尾
	while (tail)
	{
		if (tail->data == x)
		{
			return tail;
		}
		tail = tail->next;
	}
	//没找到
	return NULL;
}
//单链表在pos之后插入X
void SListPosAfter(SL* pos,DataType x)
{
	//创建一个新节点
	struct SListNode* newnode = SListBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//单链表在pos之前插入X
void SListPosPrev(SL** phead,SL* pos,DataType x)
{
	assert(phead);
	//pos的位置不能NULL
	assert(pos);
	//创建一个新节点
	struct SListNode* newnode = SListBuyNode(x);
	
	//如果pos指向NULL的情况,也就是pos == *phead
	if (pos == *phead)
	{
		*phead = newnode;
		(*phead)->next = pos;
	}
	else//多个节点的情况
	{
		SL* cur = *phead;
		SL* prev = NULL;
		//要找到pos前一个位置
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
 
//删除pos位置
void SListErase(SL** phead,SL* pos)
{
	assert(pos);
	assert(phead);
	//如果只有一个节点pos == *phead
	if (pos == *phead)
	{
		*phead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		//多个节点的情况
		SL* cur = *phead;
		SL* prev = NULL;
		//要找到pos前一个位置
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的位置
void SListEraseAfter(SL* pos)
{
	assert(pos && pos->next);//pos位置不为NULL,并且pos后面的位置不为NULL，才能删除pos后面的位置
	SL* PosAfter = pos->next;
	pos->next = PosAfter->next;
	free(PosAfter);
	PosAfter = NULL;
}
//销毁链表
void SListDestory(SL** phead)
{
	SL* tail = *phead;
	while (tail)
	{
		tail = tail->next;
		free(*phead);
		*phead = tail;
	}
}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include"SListexe.h"
void test1()
{
	SL* s1 = NULL;//初始化
	//SListPushBack(&s1,1);
	//SListPushBack(&s1, 2);
	//SListPushBack(&s1, 3);
	SListPushFront(&s1,4);
	SListPushFront(&s1, 3);
	/*SListprint(s1);*/
	/*SListPushFront(&s1, 4);*/
	//SListPopFront(&s1);
	//SListPopFront(&s1);
	SListprint(s1);

	
	SL* pos = SListFind(s1,3);
	if (pos)
	{
		SListPosAfter(pos,20);
		SListPosPrev(&s1,pos,30);
		SListPosPrev(&s1,pos,50);
		/*SListErase(&s1,pos);*/
		/*printf("%d",pos->data);*/
		SListEraseAfter(pos);
	}
	SListprint(s1);
}
int main()
{
	test1();
}