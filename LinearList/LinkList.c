/*
线性表的实现——单链表 C语言
- 逻辑结构元素相邻，存储结构上不一定相邻 可能分布在各个内存块
- 分为带有头节点与不带头节点的链表
- 每个结点包括一个元素与指向下一个节点的指针
*/

#include <stdio.h>

#define MAX_LENGTH 10
#define ElemType int

typedef struct LNode{
    
}LNode,*LinkList;


//1.初始化顺序表
void InitLst(LinkList *L){
    
}

//2.返回表长
int Length(LinkList L){

}

//3.按值查找 返回出现的第一个下标
int LocateElem(LinkList L,ElemType e){

}

//4.按位查找 返回元素
ElemType GetElem(LinkList L,int i){

}

//5.在位置i插入元素e
void ListInsert(LinkList *L,int i,ElemType e){

}

//6.删除顺序表下标为i的元素并用e返回
void ListDelete(LinkList *L,int i,ElemType &e){

}

//7.打印顺序表元素
void PrintList(LinkList L){

}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(LinkList L){

}

//9.销毁顺序表 释放内存空间
void DestroyList(LinkList *L){

}