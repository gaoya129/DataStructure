/*
线性表的实现——循环单链表/双链表 （这里实现的是单链表）
- 逻辑结构元素相邻，存储结构上不一定相邻 可能分布在各个内存块
- 分为带有头节点与不带头节点的单链表，含有头结点的链表下标从头结点开始计，头结点下标为0
- 结点结构与单链表、双链表结构相同，不同的是最后一个结点的next指针指向头结点
    - 特殊之处在于循环的结束条件是判断是否为头结点 
- 对于循环单链表来说 建立之后返回尾指针较方便 访问头尾结点时间复杂度均为O(1)
- 对于循环双链表来说 建立之后返回头指针尾指针都可以
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define ElemType int

typedef struct CNode{
    ElemType data;
    struct CNode *next;
}CNode,*CList;


//1.建立循环单链表
//头插法
CList HeadInsert(CList &L){
    CNode *p,*t;ElemType x;
    L = (CList)malloc(sizeof(CNode));
    L->next = NULL;
    cin>>x;
    int cnt = 0;
    while(x != -1){
        t = (CNode *)malloc(sizeof(CNode));
        t->data = x;
        t->next = L->next;
        L->next = t;
        if(cnt == 0){ p = t;cnt++; }
        cin>>x;
    } p->next = L;
    return p;//尾指针
}


//尾插法
CList TailInsert(CList &L){
    CNode *p,*t;ElemType x;
    L = (CList)malloc(sizeof(CNode));
    L->next = NULL;
    p = L;
    cin>>x;
    while(x != -1){
        t = (CNode *)malloc(sizeof(CNode));
        t->data = x;
        t->next = p->next;
        p->next = t;
        p = t;
        cin>>x; 
    } p->next = L;
    return p;
}


//2.返回表长
int Length(CList L){
    CNode *p = L;int cnt = 0;
    while(p->next != L){
        cnt++;p = p->next;
    }
    return cnt;
}

//3.按值查找 返回对应的结点 否则返回NULL
CNode * LocateElem(CList L,ElemType e){
    CNode *p = L->next;
    while(p != L && p->data != e){
        p = p->next;
    }
    return (p == L)? NULL:p;
}

//4.按位查找 返回该结点
CNode * GetElem(CList L,int i){
    CNode *p = L;int index = 0;
    if(i < index || i > Length(L)) return NULL;
    while(index < i){
        p = p->next;index++;
    }
    return p;
}

//5.在位置i插入元素e
//实际上因为循环链表的特性 可以循环遍历
void ListInsert(CList &L,int i,ElemType e){
    CNode *p = GetElem(L,i-1);
    if(p != NULL){
        CNode *t = (CNode *)malloc(sizeof(CNode));
        t->data = e;
        t->next = p->next;
        p->next = t;
    }else cout<<"Invalid index\n";
}

//6.删除链表下标为i的元素并用e返回
void ListDelete(CList &L,int i,ElemType &e){
    CNode *p = GetElem(L,i-1);
    if(p != NULL){
        CNode *t = p->next;
        p->next = t->next;
        e = t->data;
        free(t);
    }else cout<<"Invalid index\n";
}

//7.打印顺序表元素
void PrintList(CList L){
    cout<<"Now the List has "<<Length(L)<<" elements,they are as bellow:"<<endl;
    CNode *p = L->next;
    while(p != L){
        cout<<p->data<<"\t";
        p = p->next;
    }cout<<"\n";
}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(CList L){
   return (L->next == L)? true:false;
}

//9.销毁顺序表 释放内存空间
void DestroyList(CList &L){
    CNode *p = L,*s;
    while(p->next != L){
        s = p->next;
        p->next = s->next;
        free(s);
    } s = NULL;
}

int main(){
    CList L;
    cout<<"please enter the data:(-1 to terminated)"<<endl;
    //HeadInsert(L);
    TailInsert(L);
    cout<<"Create list complete\n";
    PrintList(L);

    CNode *p,*t;
    ElemType e = 3;int i = 3;
    p = LocateElem(L,e);
    cout<<"the elem "<<e<<" is at the node "<<p<<",data is "<<p->data<<endl;
    t = GetElem(L,i);
    cout<<"the elem at the index "<<i<<" is "<<t->data<<endl;

    ElemType data = 9;int j = 4;
    cout<<"Insert elem "<<data<<" at index "<<i<<endl;
    ListInsert(L,i,data);
    PrintList(L);
    
    ListDelete(L,j,data);
    cout<<"Delete elem at index "<<j<<", the elem is "<<data<<endl;
    PrintList(L);

    DestroyList(L);
    PrintList(L);
    return 0;
}

/*OUTPUT1 HeadInsert
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
Create list complete
Now the List has 6 elements,they are as bellow:
6       5       4       3       2       1
the elem 3 is at the node 0x10319c0,data is 3
the elem at the index 3 is 4
Insert elem 9 at index 3
Now the List has 7 elements,they are as bellow:
6       5       9       4       3       2       1
Delete elem at index 4, the elem is 4
Now the List has 6 elements,they are as bellow:
6       5       9       3       2       1
Now the List has 0 elements,they are as bellow:

*/

/*OUTPUT2 TailInsert
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
Create list complete
Now the List has 6 elements,they are as bellow:
1       2       3       4       5       6
the elem 3 is at the node 0x10919c0,data is 3
the elem at the index 3 is 3
Insert elem 9 at index 3
Now the List has 7 elements,they are as bellow:
1       2       9       3       4       5       6
Delete elem at index 4, the elem is 3
Now the List has 6 elements,they are as bellow:
1       2       9       4       5       6
Now the List has 0 elements,they are as bellow:

*/