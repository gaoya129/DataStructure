/*
线性表的实现——顺序表 C语言
- 逻辑结构与存储结构元素均相邻，且顺序存储
- 分为静态的与动态的
-- 静态顺序表直接定义数组
-- 动态顺序表C语言使用malloc C++使用new
*/

#include <stdio.h>

#define MAX_LENGTH 10
#define ElemType int

typedef struct SequenceList{
    //ElemType data[MAX_LENGTH];
    ElemType *data;
    int length;
}SqList;

//1.初始化顺序表
void InitLst(SqList *L){
    //L.data = new ElemType [MAX_LENGTH];
    L.data = (* ElemType)malloc(MAX_LENGTH*sizeof(ElemType));
    L.length = 0;
}

//2.返回表长
int Length(SqList L){

}

//3.按值查找 返回出现的第一个下标
int LocateElem(SqList L,ElemType e){

}

//4.按位查找 返回元素
ElemType GetElem(SqList L,int i){

}

//5.在位置i插入元素e
void ListInsert(SqList *L,int i,ElemType e){

}

//6.删除顺序表下标为i的元素并用e返回
void ListDelete(SqList *L,int i,ElemType &e){

}

//7.打印顺序表元素
void PrintList(SqList L){

}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(SqList L){

}

//9.销毁顺序表 释放内存空间
void DestroyList(SqList *L){

}