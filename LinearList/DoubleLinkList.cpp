/*
线性表的实现——双链表
- 逻辑结构元素相邻，存储结构上不一定相邻 可能分布在各个内存块
- 分为带有头节点与不带头节点的单链表，含有头结点的链表下标从头结点开始计，头结点下标为0
- 每个结点包括一个数据与指向上一个结点和下一个结点的指针
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define ElemType int

typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DList;

//1.建立双链表
//头插法
DList HeadInsert(DList &L){
    DNode *p,*t;ElemType x;
    L = (DList)malloc(sizeof(DNode));
    L->prior = L->next = NULL;
    p = L;
    cin>>x;
    while(x != -1){
        t = (DNode *)malloc(sizeof(DNode));
        t->data = x;
        t->prior = p;
        t->next = p->next;
        if(p->next != NULL)p->next->prior = t;
        p->next = t;
        cin>>x;
    }
    return L;
}


//尾插法
DList TailInsert(DList &L){
    DNode *p,*t;ElemType x;
    L = (DList)malloc(sizeof(DNode));
    L->prior = L->next = NULL;
    p = L;
    cin>>x;
    while(x != -1){
        t = (DNode *)malloc(sizeof(DNode));
        t->data = x;
        t->next = NULL;
        t->prior = p;
        p->next = t;
        p = t;
        cin>>x;
    }
    return L;
}


//2.返回表长
int Length(DList L){
    DNode *p = L->next;int cnt = 0;
    while(p != NULL){
        cnt++;p = p->next;
    }
    return cnt;
}

//3.按值查找 返回对应的结点 否则返回NULL
DNode * LocateElem(DList L,ElemType e){
    DNode *p = L->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

//4.按位查找 返回该结点
DNode * GetElem(DList L,int i){
    DNode *p = L;int index = 0;
    if(i < 0 || i > Length(L))return NULL;
    while(index < i){
        index++;
        p = p->next;
    }
    return p;
}

//5.在位置i插入元素e
void ListInsert(DList &L,int i,ElemType e){
    DNode *p = GetElem(L,i-1);
    if(p != NULL){
        DNode *t = (DNode *)malloc(sizeof(DNode));
        t->data = e;
        t->prior = p;
        t->next = p->next;
        if(p->next != NULL)p->next->prior = t;
        p->next = t;
    }else cout<<"Invalid index\n";
}

//6.删除链表下标为i的元素并用e返回
void ListDelete(DList &L,int i,ElemType &e){
    DNode *p = GetElem(L,i-1);
    if(p != NULL){
        DNode *t = p->next;
        p->next = t->next;
        t->next->prior = p;
        e = t->data;
        free(t);
    }else cout<<"Invalid index\n";
}

//7.打印顺序表元素
void PrintList(DList L){
    cout<<"Now the DList has "<<Length(L)<<" elements,they are as bellow:"<<endl;
    DNode *p = L;
    cout<<"Forward Direction:";
    while(p->next != NULL){
        p = p->next;cout<<p->data<<"\t";
    }cout<<"\n";
    cout<<"Reverse Direction:";//为了验证prior指针有没有错误
    while(p->prior != NULL){
        cout<<p->data<<"\t";p = p->prior;
    }cout<<"\n";
}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(DList L){
   return (L->next == NULL)? true:false;
}

//9.销毁顺序表 释放内存空间
void DestroyList(DList &L){
    //与单链表一致
    DNode * p = L,*s;
    while(p->next != NULL){
        s = p->next;
        p->next = s->next;
        free(s);
    }
    p->next = s = NULL;
}

int main(){
    DList L;
    cout<<"please enter the data:(-1 to terminated)"<<endl;
    HeadInsert(L);
    //TailInsert(L);
    cout<<"Create list complete\n";
    PrintList(L);

    DNode *p,*t;
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

/*OUTPUT1 双链表尾插法会更方便
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
Create list complete
Now the DList has 6 elements,they are as bellow:
Forward Direction:1     2       3       4       5       6
Reverse Direction:6     5       4       3       2       1
the elem 3 is at the node 0x10a19d0,data is 3
the elem at the index 3 is 3
Insert elem 9 at index 3
Now the DList has 7 elements,they are as bellow:
Forward Direction:1     2       9       3       4       5       6
Reverse Direction:6     5       4       3       9       2       1
Delete elem at index 4, the elem is 3
Now the DList has 6 elements,they are as bellow:
Forward Direction:1     2       9       4       5       6
Reverse Direction:6     5       4       9       2       1
Now the DList has 0 elements,they are as bellow:
Forward Direction:
*/

/*OUTPUT2
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
Create list complete
Now the DList has 6 elements,they are as bellow:
Forward Direction:6     5       4       3       2       1
Reverse Direction:1     2       3       4       5       6
the elem 3 is at the node 0xff19d0,data is 3
the elem at the index 3 is 4
Insert elem 9 at index 3
Now the DList has 7 elements,they are as bellow:
Forward Direction:6     5       9       4       3       2       1
Reverse Direction:1     2       3       4       9       5       6
Delete elem at index 4, the elem is 4
Now the DList has 6 elements,they are as bellow:
Forward Direction:6     5       9       3       2       1
Reverse Direction:1     2       3       9       5       6
Now the DList has 0 elements,they are as bellow:
Forward Direction:
Reverse Direction:
*/