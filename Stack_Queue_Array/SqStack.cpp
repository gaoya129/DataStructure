/*
线性表的实现——顺序栈
- 栈的顺序存储实现
- 栈的特点是后进先出，只在栈顶插入与删除
- 常用操作 Init/Destroy push/pop getTop EmptyStack
- 初始化可以将栈顶指针设置为-1或0 其他操作会有所不同 这里设为-1
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define ElemType int
#define MaxSize 10

typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;

//1.初始化栈 设置栈顶指针
void InitStack(SqStack &S){
    S.top = -1;
}

//2.销毁栈 顺序栈用不到这个操作其实
void DestroyStack(SqStack &S){
    //delete S.data; 但是静态的数组会自动回收 不需要手动销毁
}

//3.将元素x入栈
bool Push(SqStack &S,ElemType x){
    if(S.top == MaxSize-1) return false;
    S.top += 1;
    S.data[S.top] = x;
    //S.data[++S.top] = x; 等价于上面两句
    return true;
}


//4.将栈顶元素出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    S.top -= 1;
    //x = S.data[S.top--];
    return true;
}

//5.获得栈顶元素
bool getTop(SqStack &S,ElemType &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
}


void printStack(SqStack &S){
    cout<<"Now the stack has "<<S.top+1<<" elements:\n";
    for(int i = 0 ; i <= S.top ; i++ ){
        cout<<S.data[i]<<"\t";
    }cout<<endl;
}

int main(){
    SqStack S;
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

/*OUTPUT
Now the stack has 6 elements:
1       2       3       4       5       6
The top element is 6
Delete element 6
Delete element 5
Now the stack has 4 elements:
1       2       3       4
*/