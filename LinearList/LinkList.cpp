/*
线性表的实现——单链表
- 逻辑结构元素相邻，存储结构上不一定相邻 可能分布在各个内存块
- 分为带有头节点与不带头节点的单链表，含有头结点的链表下标从头结点开始计，头结点下标为0
- 每个结点包括一个数据与指向下一个节点的指针
- 插入包括头插法、尾插法
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;


//1.建立单链表
//头插法
LinkList HeadInsert(LinkList &L){
    LNode * t;ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    if(L != NULL)cout<<"Head Insert:create head node suceed."<<endl;
    L->next = NULL;
    cout<<"please enter the data:(-1 to terminated)"<<endl;
    cin>>x;
    while(x != -1){
        t = (LNode *)malloc(sizeof(LNode));
        if(t != NULL) cout<<"create node for data "<<x<<endl;
        t->data = x;
        t->next = L->next;
        L->next = t;
        cin>>x;
    }cout<<"Head Insert complete\n";
}

//尾插法
LinkList TailInsert(LinkList &L){
    LNode *p,*t;ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    if(L != NULL)cout<<"Tail Insert:create head node suceed."<<endl;
    L->next = NULL;
    p = L;
    cout<<"please enter the data:(-1 to terminated)"<<endl;
    cin>>x;
    while(x != -1){
        t = (LNode *)malloc(sizeof(LNode));
        if(t != NULL) cout<<"create node for data "<<x<<endl;
        t->data = x;
        t->next = NULL;
        p->next = t;
        p = t;
        cin>>x;
    }cout<<"Tail Insert complete\n";
}

//2.返回表长
int Length(LinkList L){
    int cnt = 0;
    LNode *p = L;
    while(p->next != NULL){
        cnt++;
        p = p->next;   
    }
    return cnt;
}

//3.按值查找 返回对应的结点 否则返回NULL
LNode * LocateElem(LinkList L,ElemType e){
    LNode *p = L->next;
    while(p != NULL && p->data != e){
        p = p->next; 
    }
    return p;
}

//4.按位查找 返回该结点
LNode * GetElem(LinkList L,int i){
    int j = 0;LNode *p = L;
    if(i < 0)return NULL;
    while(j < i && p != NULL){
        j++;p = p->next;
    }
    return p;
}

//5.在位置i插入元素e
void ListInsert(LinkList &L,int i,ElemType e){
    LNode *p = GetElem(L,i-1);
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//6.删除链表下标为i的元素并用e返回
void ListDelete(LinkList &L,int i,ElemType &e){
    LNode *p = GetElem(L,i-1);
    LNode *s = p->next;
    p->next = s->next;
    e = s->data;
    free(s);
}

//7.打印顺序表元素
void PrintList(LinkList L){
    cout<<"Now the List has "<<Length(L)<<" elements,they are as bellow:"<<endl;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        cout<<p->data<<"\t";   
    }
    cout<<"\n";
}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(LinkList L){
    return (L->next == NULL)? true:false;
}

//9.销毁顺序表 释放内存空间
void DestroyList(LinkList &L){
    cout<<"Destroy start"<<endl;
    LNode * p = L;LNode *s;
    while(p->next != NULL){
        s = p->next;
        p->next = s->next;
        free(s);
    }
    p->next = s = NULL;
    cout<<"end\n";
}

int main(){
    LinkList L;
    // HeadInsert(L);
    TailInsert(L);
    PrintList(L);

    LNode *p,*t;
    ElemType e = 3;
    p = LocateElem(L,e);
    cout<<"the elem "<<e<<" is at the node "<<p<<",data is "<<p->data<<endl;
    t = GetElem(L,3);
    cout<<"the elem at the index 3 is "<<t->data<<endl;

    ListInsert(L,3,9);
    PrintList(L);
    ListDelete(L,3,e);
    PrintList(L);

    DestroyList(L);
    PrintList(L);
    return 0;
}

/*OUTPUT1
Head Insert:create head node suceed.
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
create node for data 1
create node for data 2
create node for data 3
create node for data 4
create node for data 5
create node for data 6
Head Insert complete
Now the List has 6 elements,they are as bellow:
6       5       4       3       2       1
the elem 3 is at the node 0xf619c0,data is 3
the elem at the index 3 is 4
Now the List has 7 elements,they are as bellow:
6       5       9       4       3       2       1
Now the List has 6 elements,they are as bellow:
6       5       4       3       2       1
Destroy start
end
Now the List has 0 elements,they are as bellow:

*/

/*OUTPUT2
Tail Insert:create head node suceed.
please enter the data:(-1 to terminated)
1 2 3 4 5 6 -1
create node for data 1
create node for data 2
create node for data 3
create node for data 4
create node for data 5
create node for data 6
Tail Insert complete
Now the List has 6 elements,they are as bellow:
1       2       3       4       5       6
the elem 3 is at the node 0x11519c0,data is 3
the elem at the index 3 is 3
Now the List has 7 elements,they are as bellow:
1       2       9       3       4       5       6
Now the List has 6 elements,they are as bellow:
1       2       3       4       5       6
Destroy start
end
Now the List has 0 elements,they are as bellow:

*/
