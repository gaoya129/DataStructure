/*
线性表的实现——顺序表
- 逻辑结构与存储结构元素均相邻，且顺序存储
- 分为静态的与动态的
-- 静态顺序表直接定义数组
-- 动态顺序表C语言分配空间使用malloc C++使用new
    C语言释放空间用free C++用delete
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define ElemType int


typedef struct SequenceList{
    //ElemType data[MAX_LENGTH];
    ElemType *data;
    int length;
}SqList;

//1.初始化顺序表
void InitList(SqList &L){
    //L.data = new ElemType [MAX_LENGTH];
    L.data = (ElemType *)malloc(MAX_LENGTH*sizeof(ElemType));
    L.length = 0;
    if(L.data != NULL) cout<<"Init finished."<<endl;
}

//2.返回表长
int Length(SqList L){
    return L.length;
}

//3.按值查找 返回出现的第一个下标
int LocateElem(SqList L,ElemType e){
    int index = -1;
    for(int j = 0; j < L.length; j++){
        if(L.data[j] == e) {
            index = j;
            break;
        }
    }
    cout<<"the elem "<<e<<" is at the index "<<index<<endl;
    return index;
}

//4.按位查找 返回元素
ElemType GetElem(SqList L,int i){
    if(L.length == 0){cout<<"Error:No Elements."<<endl;return false;}
    if(i < 0 || i >= L.length){cout<<"Error:Invalid input index"<<endl; return false;}
    cout<<"the elem at the index "<<i<<" is "<<L.data[i]<<endl;
    return L.data[i];
}

//5.在位置i插入元素e
void ListInsert(SqList &L,int i,ElemType e){
    if(i < 0 || L.length == MAX_LENGTH || i+1 >= MAX_LENGTH){cout<<"Error:Invalid input index"<<endl; return;}
    for(int j = L.length; j > i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i] = e;cout<<"insert "<<e<<endl;
    L.length++;
}

//6.删除顺序表下标为i的元素并用e返回
void ListDelete(SqList &L,int i,ElemType &e){
    if(i < 0 || i >= L.length){cout<<"Error:Invalid input index"<<endl;  return;}
    e = L.data[i];
    for(int j = i; j < L.length-1; j++){
        L.data[j] = L.data[j+1];
    }cout<<"delete "<<e<<endl;
    L.length--;
}

//7.打印顺序表元素
void PrintList(SqList L){
    cout<<"Now the List has "<<Length(L)<<" elements,they are as bellow:"<<endl;
    for(int j = 0; j < L.length; j++){
        cout<<L.data[j]<<"\t";
    }
    cout<<"\n";
}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(SqList L){
    return (L.length == 0)? true:false;
}

//9.销毁顺序表 释放内存空间
void DestroyList(SqList &L){
    free(L.data);
    L.data = NULL;
    L.length = 0;
}

int main(){
    SqList L;
    InitList(L);
    cout<<"After Init"<<endl;
    PrintList(L);

    int a[] = {1,2,3,4,5};
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)ListInsert(L,0,a[i]);
    cout<<"After Insert"<<endl;
    PrintList(L);

    GetElem(L,1);
    LocateElem(L,1);
    LocateElem(L,11);   

    int e = 0;
    ListDelete(L,1,e);
    ListDelete(L,2,e);
    PrintList(L);

    DestroyList(L);
    cout<<"After Destroy"<<endl;
    PrintList(L);
    return 0;
}

/*OUTPUT
Init finished.
After Init
Now the List has 0 elements,they are as bellow:

insert 1
insert 2
insert 3
insert 4
insert 5
After Insert
Now the List has 5 elements,they are as bellow:
5       4       3       2       1
the elem at the index 1 is 4
the elem 1 is at the index 4
the elem 11 is at the index -1
delete 4
delete 2
Now the List has 3 elements,they are as bellow:
5       3       1
After Destroy
Now the List has 0 elements,they are as bellow:

*/