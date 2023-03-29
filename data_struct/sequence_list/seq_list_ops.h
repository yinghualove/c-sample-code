#ifndef _SEQ_LIST_OPS_H_
#define _SEQ_LIST_OPS_H

typedef int Status;   // fun of struct
typedef int Elemtype; // data of struct

typedef struct
{
    Elemtype *elem; // elem in the array
    int length;     // the real length of the seqlist
    int listsize;   // seqlist creat length of the array
} SeqList;

//sequence list options
Status InitList(SeqList *L);
Status DestroyList(SeqList *L);
Status ListEmpty(SeqList *L);
Status ListLength(SeqList *L);
Status WriteList(SeqList *L);
Status Getelem(SeqList *L, int i, Elemtype *e);
Status Locateelem(SeqList *L, Elemtype e);
Status Priorelem(SeqList *L, Elemtype cur_e, Elemtype *pre_e);
Status Nextelem(SeqList *L, Elemtype cur_e, Elemtype *next_e);
Status ListInsert(SeqList *L, int i, Elemtype e);
Status Listdelete(SeqList *L, int i, Elemtype *e);


#endif /*_SEQ_LIST_OPS_H*/