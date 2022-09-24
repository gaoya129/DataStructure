/*
线性表的实现——循环链式队列
- 队列的链式存储实现
- 队列的特点是先进先出，在队尾插入，在队头删除
    - 有队头指针、队尾指针 普通的链式队列就是单链表结构
    - 链表不会有长度溢出的问题 可以随时增加减少 也就是没有队满的情况
- 队头指针指向第一个元素，循环队列不带头结点
- 队尾指针指向队尾元素（如果放在队尾元素的后一个位置且是固定容量 方便循环队列判断队满时）
- 循环单链表链式队列操作
    - 队空判断条件是 队头指针==队尾指针
    - 让队尾指针放在元素的后一个位置 队满条件即为 Q.rear->next = Q.front
    - 一开始队空 有新元素入队时将rear指向的结点data赋值 然后rear后移指向一个新申请的空结点
*/

#include <iostream>
#include <vector>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define ElemType int

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LNode;

typedef struct CycleLinkQueue{
    LNode *front,*rear;
}CLQueue;

void InitQueue(CLQueue &Q){
    Q.front = (LNode *)malloc(sizeof(LNode));
    Q.rear = Q.front;
    Q.rear->next = Q.front;
}

bool QueueEmpty(CLQueue Q){
    return (Q.front == Q.rear)? true:false;
}

void EnQueue(CLQueue &Q,ElemType x){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x; p->next= Q.rear->next;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue(CLQueue &Q,ElemType &x){
    if(QueueEmpty(Q)) return ;
    LNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear) Q.rear = Q.front;
    free(p);
}

void GetHead(CLQueue Q,ElemType &x){
    x = Q.front->next->data;
}

int main(){
    CLQueue Q;
    vector<ElemType> a = {1,2,3,4,5};
    InitQueue(Q);
    for(auto &x : a)EnQueue(Q,x);
    ElemType t;
    GetHead(Q,t);
    cout<<t<<endl;
    while(!QueueEmpty(Q)){
        DeQueue(Q,t);
        cout<<t<<"\t";
    }
    return 0;
    return 0;
}