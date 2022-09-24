/*
线性表的实现——链栈
- 栈的链式存储实现
- 栈的特点是后进先出，只在栈顶插入与删除
    - 链栈的插入与删除相当于头插法 删除头部元素
- 栈顶指针这次指向的是结点
- 链栈的实现分为带头结点的和不带头结点的 这里实现的是不带头结点
    - 不带头结点的链表为空时 头指针指向NULL
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define ElemType int
#define MaxSize 10

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LNode,*LStack;

//1.初始化栈 设置栈顶指针
void InitStack(LStack &S){
    S = NULL;//判空条件
}

//2.销毁栈
void DestroyStack(LStack &S){
    if(S == NULL)return ;
    LNode *p = S;
    while(S != NULL){
        S = S->next;
        free(p);
        p = S;
    }
}

//3.将元素x入栈
void Push(LStack &S,ElemType x){
    LNode * p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = S;
    S = p;
}


//4.将栈顶元素出栈
bool Pop(LStack &S,ElemType &x){
    if(S == NULL)return false;
    LNode *p = S;
    x = S->data;
    S = S->next;
    free(p);
    return true;
}

//5.获得栈顶元素
bool getTop(LStack &S,ElemType &x){
    if(S == NULL)return false;
    x = S->data;
    return true;
}


void printStack(LStack &S){
    cout<<"Now the stack has elements:\n";
    LNode *p = S;
    while(p != NULL){
        cout<<p->data<<"\t";
        p = p->next;
    }cout<<endl;
}

int main(){
    LStack S;
    InitStack(S);
    for(int i = 1 ; i <= 6 ; i++)Push(S,i);
    printStack(S);
    ElemType x;
    getTop(S,x);
    cout<<"The top element is "<<x<<endl;
    Pop(S,x);cout<<"Delete element "<<x<<endl;
    Pop(S,x);cout<<"Delete element "<<x<<endl;
    printStack(S);
    return 0;
}

/*
Now the stack has elements:
6       5       4       3       2       1
The top element is 6
Delete element 6
Delete element 5
Now the stack has elements:
4       3       2       1
*/