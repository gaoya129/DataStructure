/*
线性表的实现——链式队列
- 队列的链式存储实现
- 队列的特点是先进先出，在队尾插入，在队头删除
    - 有队头指针、队尾指针 普通的链式队列就是单链表结构
    - 链表不会有长度溢出的问题 可以随时增加减少 也就是没有队满的情况
- 队头指针指向第一个元素，这里是带头结点的链表
- 队尾指针指向最后一个元素
- 单链表链式队列操作
    - 队空判断条件是 队头指针==队尾指针
    - 入队时将新结点放在最后
    - 出队时将队头指针指向的结点出队 要区分只有一结点时候的情况 
    要修改队尾指针与队头指针相同 表示队空
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

typedef struct LinkQueue{
    LNode *front,*rear;
}LQueue;

void InitQueue(LQueue &Q){
    Q.front = (LNode *)malloc(sizeof(LNode));
    Q.rear = Q.front;
    Q.rear->next = NULL;
}

bool QueueEmpty(LQueue Q){
    return (Q.front == Q.rear)? true:false;
}

void EnQueue(LQueue &Q,ElemType x){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x; p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue(LQueue &Q,ElemType &x){
    if(QueueEmpty(Q)) return ;
    LNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear) Q.rear = Q.front;
    free(p);
}

void GetHead(LQueue Q,ElemType &x){
    x = Q.front->next->data;
}

int main(){
    LQueue Q;
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
}