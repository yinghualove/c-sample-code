/*c++ data struct seqlist*/
#include<stdio.h>
#include <stdlib.h>  //
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0            //wrong
#define INFEASIBLE -1     //不可行
#define OVERFLOW -2       //溢出
#define LIST_SIZE 10     //线性表最大长度
typedef int Status;      // fun of struct，函数类型
typedef int Elemtype;    //data of struct，数组类型

typedef struct{
    Elemtype *elem;      //elem in the array,动态分配的数组的指针
    int length;          //顺序表当前长度
    int MaxSize;        //顺序表的最大容量
}SeqList;

/*
创建一个顺序表
InitList(L)
*/
Status InitList(SeqList &L){
    //用malloc申请一片连续的空间
    L.elem = (Elemtype *)malloc(LIST_SIZE*sizeof(Elemtype));
    if(!L.elem)
    exit (INFEASIBLE);
    L.length = 0;
    L.MaxSize = LIST_SIZE;
    printf("InitList finish\n");
    return OK;
}

/*
销毁一个顺序表
DestoryList(L)
*/
Status DestoryList(SeqList &L){
    while(!L.elem)
    free(L.elem);
    L.length = 0;
    printf("destory finish\n");
    return OK;
}

/*
向线性表中写数据
WriteList(L)
*/

SeqList WriteList(SeqList &L){
    printf("线性表的长度：\n");
    scanf("%d",&L.length);
    printf("输入元素：\n");
    for(int i=0;i<L.length;i++){
        scanf("%d",&L.elem[i]);
        printf("输入的线性表为:elem[%d] = %d\n",i+1,L.elem[i]);
    }
}

/*
增加动态数组长度
IncreaseList(L,len)
*/
Status IncreaseList(SeqList &L,int len){
    int *p = L.elem;
    L.elem = (Elemtype *)malloc((LIST_SIZE+len)*sizeof(Elemtype));
    for(int i = 0;i<L.length;i++){
        L.elem[i]=p[i];      //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize+len;   //顺序表长度增加len
    free(p);                    //释放原来的空间
}

/*
插入元素
ListInsert(L,i,e)
*/
Status ListInsert(SeqList &L,int i,int e){
    if(i<1||i>L.length+1)     //判断当前i的范围是否有效
    return FALSE;
    if(L.length>=L.MaxSize)   //判断存储空间是否已满，不能插入
    return FALSE;
    for(int j = L.length;j>=i;j--)   //将第i个元素及之后的元素右移
        L.elem[j]=L.elem[j-1];
    L.elem[i-1]=e;                  //在位置i出放入e
    L.length++;                     //长度加1
    printf("增加的第%d个值为%d\n",i,e);
    for(i = 0;i<L.length;i++)
    {
        printf("增加后的顺序表为:elem[%d]=%d\n",i+1,L.elem[i]);
    }
    return TRUE;

}

/*
删除
ListDelete(L,i,e)
*/
Status ListDelete(SeqList &L,int i,int &e){
    if(i<1||i>L.length)
    return FALSE;
    e = L.elem[i-1];                 //将被删除的值赋给e
    for(int j = i;j<L.length;j++)    //将第i个位置后的元素前移
        L.elem[j-1] = L.elem[j];     
    L.length--;                      //线性表长度减1
    return TRUE;
}

/*
按位查找
GetList(L,i),i的数据类型需要和elem的类型一样需要
*/
Status GetList(SeqList L,Elemtype i){
    printf("查找到的第%d个值为%d\n",i,L.elem[i-1]);
    return L.elem[i-1];  
}

/*
按值查找
LcateList(L,e)
*/
Status LocateList(SeqList L,int e){
    int i;
    for( i = 0;i<L.length;i++){
    if(L.elem[i]==e)
    {
        return i+1;
        
    }
    }
    return 0;
}

int main(){
    SeqList L;
    InitList(L);
    WriteList(L);
    ListInsert(L,4,10);
    GetList(L,4);
    LocateList(L,10);
    printf("通过按值查找到值为10在第%d个\n",LocateList(L,10));
    int e = -1;
    if(ListDelete(L,4,e))
        printf("被删除的第4个元素值为:%d\n",e);
    else
        printf("为序i不合法,删除失败\n");
    DestoryList(L);
    return 0;
}