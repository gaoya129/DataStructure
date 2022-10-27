/*非线性结构 树 包括一般树和二叉树
二叉树的实现——树的遍历
- 先序
- 中序
- 后序
- 层次遍历
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 50
#define ElemType char

using namespace std;
typedef struct BinaryTreeNode{
	ElemType ch;
	struct BinaryTreeNode *lchild, *rchild;
}BTNode,*BTree;

void PrintTree(BTNode *n,int type,int level);

BTNode* CreateTreeNode(char x,BTNode *left=NULL,BTNode *right=NULL){
    BTNode * node=(BTNode *)malloc(sizeof(BTNode));
    node->ch = x;
    node->lchild = left;
    node->rchild = right;
    cout<<"Create Node "<<x<<endl;
    return node;
}

//建立完全二叉树
void InsertTree(BTree &T,char *s){
    int len = strlen(s);
    BTNode* arr[len];//空间复杂度有点高了
    int h = ceil(log(len+1)/log(2));
    // cout<<s<<" "<<len<<endl;cout<<h<<endl;
    T = CreateTreeNode(s[0]);
    BTNode * p;arr[0] = T;
    for(int i = 1; i <= len ; i++){
        p = arr[i-1];
        if(2*i < len){
            p->lchild = CreateTreeNode(s[2*i-1]);arr[2*i-1]=p->lchild;
            p->rchild = CreateTreeNode(s[2*i]);arr[2*i]=p->rchild;
        }
        else if(2*i-1 < len)
            p->lchild = CreateTreeNode(s[2*i-1]);arr[2*i-1]=p->lchild;
    }
}

void visit(BTNode *n){
    cout<<n->ch;
}

void PreOrder(BTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BTree T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BTree T){
    #define Elem BTNode*
    typedef struct CycleQueue{
        Elem data[MAXSIZE];
        int front,rear;

        void Init(){front = 0;rear = 0;}
        bool Empty(){return front==rear;}
        void Push(Elem x){
            //为了判断队满队空会牺牲一个存储空间 rear是指向队尾元素额后一个位置
            if((rear+1)%MAXSIZE == front)return;//队满
            data[rear] = x;
            rear = (rear+1)%MAXSIZE;
        }
        void Pop(){
            if(Empty())return;//队空
            front = (front+1)%MAXSIZE;
        }
        Elem getTop(){
            if(Empty())return NULL;//队空
            return data[front];
        }
    }CQueue;
    
    CQueue Q;
    Q.Init();
    BTNode * p = T;
    Q.Push(T);
    cout<<"LevelOrder: ";
    while(p != NULL || !Q.Empty()){
        p = Q.getTop();
        if(p->lchild != NULL)Q.Push(p->lchild);
        if(p->rchild != NULL)Q.Push(p->rchild);
        cout<<p->ch;
        Q.Pop();
    }cout<<endl;
}

int main(){
    BTree T;
    char s[] = {'A','B','C','D','E','F','\0'};//层次遍历的序列
    InsertTree(T,s);
    PrintTree(T,0,0);
    cout<<"PreOrder: ";PreOrder(T);cout<<endl;
    cout<<"InOrder: ";InOrder(T);cout<<endl;
    cout<<"PostOrder: ";PostOrder(T);cout<<endl;
    LevelOrder(T);
    return 0;
}
/*最后输出
Create Node A
Create Node B
Create Node C
Create Node D
Create Node E
Create Node F
        / C
                \ F
A
                / E
        \ B
                \ D
PreOrder: ABDECF
InOrder: DBEAFC
PostOrder: DEBFCA
LevelOrder: ABCDEF
*/
// 逆转90度打印的二叉树:   type : 0表示根节点，１表示左节点，２表示右节点. level表示层次，用于控制显示的距离
void PrintTree(BTNode *n, int type,  int level){
	int i;
	if (NULL == n)return;
	PrintTree(n->rchild, 2, level+1);

	switch (type){
	    case 0:
	    	cout<<n->ch<<endl;
	    	break;
	    case 1:
	    	for (i = 0; i < level; i++)	printf("\t");
	    	cout<<"\\ "<<n->ch<<endl;
	    	break;
	    case 2:
	    	for (i = 0; i < level; i++)	printf("\t");
	    	cout<<"/ "<<n->ch<<endl;
	    	break;	
	}
	PrintTree(n->lchild, 1,  level+1);
}

