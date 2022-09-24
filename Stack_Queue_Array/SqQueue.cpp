/*
线性表的实现——顺序队列
- 队列的顺序存储实现
- 队列的特点是先进先出，在队尾插入，在队头删除
    - 有队头指针、队尾指针 入队队尾指针加一，出队队头指针加一，加一之后都要%MaxSize！！！（实现循环的关键点
    - 普通的顺序队列会有假溢出的情况（队头指针大于等于MaxSize 但队不满）且不好判断队满情况
- 队头指针可以指向第一个元素，也可以指向队头元素的前一个位置
- 队尾指针可以指向最后一个元素，也可以指向队尾元素的后一个位置
- 循环队列操作
    - 队空判断条件是 队头指针==队尾指针
    - MaxSize=n+1 为方便判断队满可以将[0...n]空一个位置不放元素 只能存放n个元素
    让队尾指针放在元素的后一个位置 队满条件即为 (Q.rear+1)%MaxSize == Q.front
    - 队的长度是(Q.rear-Q.front+MaxSize)%MaxSize
*/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

#define ElemType int
#define MaxSize 11

typedef struct SequenceQueue{
    ElemType data[MaxSize]; 
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = 0;//放在队头元素这 0~MaxSize-2用于存储元素
    Q.rear = 0;//放在队尾元素的后一个位置 放入第一个元素之后就可以了
}

bool QueueEmpty(SqQueue Q){
    return (Q.front == Q.rear)? true:false;
}

void EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize == Q.front) return ;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
}

void DeQueue(SqQueue &Q,ElemType &x){
    if(Q.front == Q.rear) return ;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
}

void GetHead(SqQueue Q,ElemType &x){
    if(Q.front == Q.rear) return ;
    x = Q.data[Q.front];
}

int main(){
    SqQueue Q;
    vector<ElemType> a = {1,2,3,4,5};
    InitQueue(Q);
    for(auto &x : a)EnQueue(Q,x);
    ElemType t;
    while(!QueueEmpty(Q)){
        DeQueue(Q,t);
        cout<<t<<"\t";
    }
    return 0;
}