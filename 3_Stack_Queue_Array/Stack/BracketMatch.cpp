/*
线性表的实现——栈的应用之括号匹配
- 使用定长顺序栈
- 查看括号是否左右配对，包括{}、[]、()三种括号
- 借助栈操作实现 遇到左括号就入栈 遇到右括号就getTop
    栈顶元素如果匹配就出栈 然后直到全部匹配完
    如果中途没有匹配失败且最后栈为空 那么括号表达式合法
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define ElemType int
#define MaxSize 30

struct SqStack{
    ElemType data[MaxSize];
    int top;
};

void Inital(SqStack &S);
void Push(SqStack &S,ElemType x);
bool IsEmpty(SqStack S);
ElemType Pop(SqStack &S);
ElemType getTop(SqStack S);

//test 
//[ { ( ) } ]
//[ { ( )
//[ { (])}
void BracketMatch(SqStack &S){
    Inital(S);
    char exp[100];
    cout<<"Please enter expression of brackets:"<<endl;
    gets(exp);
    //cout<<ex;
    for(auto c : exp){
        if(c == '{' || c == '[' || c == '(')Push(S,c);
        else if(c == '}'){
            if(getTop(S) == '{')Pop(S);
            else break;
        }else if(c == ']'){
            if(getTop(S) == '[')Pop(S);
            else break;
        }else if(c == ')'){
            if(getTop(S) == '(')Pop(S);
            else break;
        }
    }
    if(IsEmpty(S))cout<<"Match Success^_^"<<endl;
    else cout<<"Match Failed-_-"<<endl;
}


int main(){
    SqStack S;
    BracketMatch(S);
    return 0;
}


void Inital(SqStack &S){
    S.top = -1;
}

void Push(SqStack &S,ElemType x){
    if(S.top == MaxSize-1) return;
    S.data[++S.top] = x;
}

bool IsEmpty(SqStack S){
    return (S.top == -1);
}

ElemType Pop(SqStack &S){
    if(IsEmpty(S)){cout<<"Stack is Empty"<<endl;return 0;}
    ElemType x = S.data[S.top--];
    return x;
}

ElemType getTop(SqStack S){
    if(IsEmpty(S)){cout<<"Stack is Empty"<<endl;return 0;}
    ElemType x = S.data[S.top];
    return x;
}
