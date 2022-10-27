/*
二叉树的实现——线索二叉树
- 只实现中序线索树 还有通过线索树实现的中序遍历 和逆中序遍历
- 前序线索树 因为左右孩子必然都是当前结点的后继 所以前驱不好找 需要三叉链表结构
- 后序线索树 因为左右孩子必然都是当前结点的前驱 所以后继不好找 需要三叉链表结构
*/
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 50
#define ElemType char

using namespace std;

typedef struct ThreadNode{
	ElemType ch;
	struct ThreadNode *lchild, *rchild;
    bool ltag,rtag;//线索标签
}TNode,*ThreadTree;

void PrintTree(TNode *n,int type,int level);
TNode* CreateTreeNode(char x,TNode *left,TNode *right);
void InsertTree(ThreadTree &T,char *s);

//初始化值为NULL
TNode *pre = NULL;
void InThread(TNode *q){
    if(q != NULL){
        InThread(q->lchild);
        // visit(T); //下面就是visit函数的内容
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = q;
            pre->rtag = 1;
            if(q == NULL) cout<<"Nextclue: "<<pre->ch<<"------>NULL"<<endl;
            else cout<<"Nextclue: "<<pre->ch<<"------>"<<q->ch<<endl;
        }
        if(q->lchild == NULL){
            //pre初始值为NULL 中序遍历的第一个访问结点前驱就是NULL
            q->lchild = pre;
            q->ltag = 1;
            if(pre == NULL) cout<<"Priorclue: "<<q->ch<<"------>NULL"<<endl;
            else cout<<"Priorclue: "<<q->ch<<"------>"<<pre->ch<<endl;
        }
        pre = q;
        InThread(q->rchild);
    }
}

void CreateThreadTree(ThreadTree T){
    TNode *q = T; 
    if(q != NULL){
        InThread(q);
        //处理最后遍历的结点 此时pre指向该结点 p是其孩子结点因为不存在故为NULL
        //虽然值为NULL 但也是线索
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//找到以p为根节点的子树 中序遍历第一个访问到的结点
//子树中最左端的结点
TNode *FirstNode(TNode *p){
    while(p->ltag != 1)p = p->lchild;
    return p;
}

//找到该结点的后继 就是下一个访问的结点
TNode *NextNode(TNode *p){
    if(p->rtag == 1)p = p->rchild;
    else p = FirstNode(p->rchild);//右子树中最左端的结点
}

//利用中序线索树实现中序遍历
void InOrder(ThreadTree T){
    TNode * p = FirstNode(T);
    while(p != NULL){
        cout<<p->ch;
        p = NextNode(p);
    }cout<<endl;
}

//找到以p为根结点的子树 在中序遍历中最后访问的结点
//子树中最右端的结点
TNode *LastNode(TNode* p){
    while(p->rtag != 1) p = p->rchild;
    return p;
}

//找到该结点的前驱 就是上一个访问的结点
TNode *PreNode(TNode* p){
    if(p->ltag == 1)return p->lchild;
    else return LastNode(p->lchild);
}
void ReInOrder(ThreadTree T){
    TNode *p = T;
    p = LastNode(T);
    while(p != NULL){
        cout<<p->ch;
        p = PreNode(p);
    }cout<<endl;
}

int main(){
    ThreadTree T;
    char s[] = {'A','B','C','D','E','F','\0'};//层次遍历的序列
    InsertTree(T,s);
    PrintTree(T,0,0);
    CreateThreadTree(T);
    cout<<"InOrder: ";InOrder(T);
    cout<<"ReverseInOrder: ";ReInOrder(T);
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
Priorclue: D------>NULL
Nextclue: D------>B
Priorclue: E------>B
Nextclue: E------>A
Priorclue: F------>A
Nextclue: F------>C
InOrder: DBEAFC
ReverseInOrder: CFAEBD
*/


TNode* CreateTreeNode(char x,TNode *left=NULL,TNode *right=NULL){
    TNode * node=(TNode *)malloc(sizeof(TNode));
    node->ch = x;
    node->lchild = left;
    node->rchild = right;
    node->ltag = 0;
    node->rtag = 0;
    cout<<"Create Node "<<x<<endl;
    return node;
}

//建立完全二叉树
void InsertTree(ThreadTree &T,char *s){
    int len = strlen(s);
    TNode* arr[len];//空间复杂度有点高了
    int h = ceil(log(len+1)/log(2));
    // cout<<s<<" "<<len<<endl;cout<<h<<endl;
    T = CreateTreeNode(s[0]);
    TNode * p;arr[0] = T;
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

void PrintTree(TNode *n, int type,  int level){
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

