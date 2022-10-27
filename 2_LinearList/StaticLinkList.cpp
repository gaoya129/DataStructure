/*
线性表的实现——静态链表
- 逻辑结构元素相邻，申请一片连续的内存空间作为链表存储空间
    - 但是逻辑上相邻的元素依然不一定物理存储空间上相邻
- 每个结点包括数据和结点的游标，即下一个结点所在的数组下标
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define ElemType int


typedef struct StaticNode{
    ElemType data;
    int index;
}SLinkList[MAX_LENGTH];
//使用SLinklist定义变量 
//就是定义了一个MAX_LENGTH大小的StaticNode类型的数组

//1.建立静态链表
//头插法
void InitList(SLinkList &L){
    L[0].data = 0;//用来存储链表长
    L[0].index = -1;//-1表示是最后一个结点
    for(int i = 1;i < MAX_LENGTH; i++){
        L[i].index = -2;//-2代表该结点为空
    }
}


//2.返回表长
int Length(SLinkList L){
    return L[0].data;
}

//3.按值查找 返回对应结点的物理位置下标
int LocateElem(SLinkList L,ElemType e){
    int cnt = 1,i = 1;
    while(cnt < Length(L) && L[i].data != e){
        cnt++; i = L[i].index;
    }return i;
}

//4.按位查找 返回该结点的数组下标
int GetElem(SLinkList L,int i){
    int index = 0;
    if(i >= MAX_LENGTH || i < 0) return -1;
    for(int j = 0; j < i ; j++) index = L[index].index;
    return index;
}

//5.在链表的第i个位置插入元素e
void ListInsert(SLinkList &L,int i,ElemType e){
    int empty=-1,index;//第一个空位置的数组下标 第i个元素对应的数组下标
    for(int j = 1 ; j < MAX_LENGTH ; j++){
        if(L[j].index == -2){
            empty = j;break;
        }
    } index = GetElem(L,i-1);
    if(empty == -1 || index == -1)return ;
    L[empty].data = e;
    L[empty].index = L[index].index;
    L[index].index = empty;
    L[0].data++;
}

//6.删除链表第i个元素并用e返回
void ListDelete(SLinkList &L,int i,ElemType &e){
    int index = GetElem(L,i-1);
    if(index == -1)return ;
    int i_index = L[index].index;
    L[index].index = L[i_index].index;
    L[i_index].index = -2;
    e = L[i_index].data;
    L[0].data--;
}

//7.打印顺序表元素
void PrintList(SLinkList L){
    cout<<"Now the SLinkList has "<<Length(L)<<" elements,they are as bellow:"<<endl;
    for(int i = 0 ; i < MAX_LENGTH; i++){
        if(L[i].index == -2)cout<<i<<endl;
        else cout<<i<<"\t"<<L[i].data<<"\t"<<L[i].index<<endl;
    }cout<<"The static list equals singlelinklist like this: "<<endl;
    int index = 0;
    for(int j = 0; j < Length(L) ; j++){
        index = L[index].index;
        cout<<L[index].data<<"\t";
    }cout<<"\n\n";
}

//8.判断顺序表是否为空返回true or false
bool IfEmpty(SLinkList L){
   return (L[0].index == -1)? true:false;
}

//9.销毁顺序表 释放内存空间
void DestroyList(SLinkList &L){
    //静态数组系统会自动释放空间
}

void testData(SLinkList &L){
    L[0].index = 1;
    L[1].data = 1;L[1].index = 6;
    L[6].data = 2;L[6].index = 2;
    L[2].data = 5;L[2].index = -1;
    L[0].data = 3;
}

int main(){
    SLinkList L;
    InitList(L);
    cout<<"Initial Complete\n";

    testData(L);
    PrintList(L);
    
    int i = 3;
    ListInsert(L,i,4);
    cout<<"Insert elem 4 at index "<<i<<endl;
    ListInsert(L,i,3);
    cout<<"Insert elem 3 at index "<<i<<endl;
    PrintList(L);

    ElemType e;
    ListDelete(L,i,e);
    cout<<"Delete elem at index "<<i<<", the elem is "<<e<<endl;
    PrintList(L);

    return 0;
}

/*OUTPUT
Initial Complete
Now the SLinkList has 3 elements,they are as bellow:
0       3       1
1       1       6
2       5       -1
3
4
5
6       2       2
7
8
9
The static list equals singlelinklist like this: 
1       2       5

Insert elem 4 at index 3
Insert elem 3 at index 3
Now the SLinkList has 5 elements,they are as bellow:
0       5       1
1       1       6
2       5       -1
3       4       2
4       3       3
5
6       2       4
7
8
9
The static list equals singlelinklist like this: 
1       2       3       4       5

Delete elem at index 3, the elem is 3
Now the SLinkList has 4 elements,they are as bellow:
0       4       1
1       1       6
2       5       -1
3       4       2
4
5
6       2       3
7
8
9
The static list equals singlelinklist like this:
1       2       4       5

*/