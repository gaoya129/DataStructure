/*
二叉树的实现——由遍历序列构建二叉树
- 前序+中序
- 后序+中序
- 层次+中序
- 前序 根结点 左子树的前序遍历 右子树的前序遍历
- 中序 左子树的中序遍历 根节点 右子树的中序遍历
- 后序 左子树的后序遍历 右子树的后序遍历 根结点
- 层次 根节点 左子树的根节点 右子树的根节点 ...
同一颗树的遍历序列
先序+中序
A B D G E C F
D G B E A F C
后序+中序
G D E B F C A
D G B E A F C
层次+中序
A B C D E F G
D G B E A F C
77 66 88 55 70 80 99 44 60
*/

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50
#define ElemType char

using namespace std;
typedef struct BinaryTreeNode{
	ElemType ch;
	struct BinaryTreeNode *lchild, *rchild;
}BTNode,*BTree;

void printStrArray(char *s,int len);
void getOrder(char *o1,char *o2,int &len1,int &len2);
void PrintTree(BTNode *n,int type,int level);

BTNode* CreateTreeNode(char x,BTNode *left=NULL,BTNode *right=NULL){
    BTNode * node=(BTNode *)malloc(sizeof(BTNode));
    node->ch = x;
    node->lchild = left;
    node->rchild = right;
    cout<<"Create Node "<<x<<endl;
    return node;
}

int findStr(char *order,int begin,int end,char s){
    for(int i = begin ; i <= end ; i ++){
        if(order[i] == s){
            // cout<<"find "<<order[i]<<" at"<<i<<endl;
            return i;
        }
    }
    return -1;
}

//根据前序遍历找到中序遍历中根的位置，从而得到前序序列中左子树右子树的序列
BTNode *FindRootNode1(char *o1,char *o2,int begin1,int end1,int begin2,int end2){
    if(begin1 > end1 || begin2 > end2){return NULL;}
    BTNode * TNode = CreateTreeNode(o1[begin1]);
    //找到就剩一个结点了 直接返回
    if(begin1 == end1) return TNode;
    int root2 = findStr(o2,begin2,end2,o1[begin1]);
    //如果有左子树右子树就继续找
    if(root2-1 >= 0){TNode->lchild = FindRootNode1(o1,o2,begin1+1,begin1+root2-begin2,begin2,root2-1);}
    if(root2+1 <= end2){TNode->rchild = FindRootNode1(o1,o2,begin1+root2-begin2+1,end1,root2+1,end2);}
    return TNode;
}

BTree Pre_InOrder2Tree(char *o1,char *o2){
    //o1是前序遍历序列 o2是中序遍历序列
    cout<<o1<<endl;
    cout<<o2<<endl;
    int len1 = strlen(o1),len2 = strlen(o2);
    // cout<<len1<<" "<<len2;
    int root1 = 0;int root2 = findStr(o2,0,len2-1,o1[root1]);
    BTree Tree = CreateTreeNode(o1[root1]);
    //有左子树
    if(root2-1 >= 0)Tree->lchild = FindRootNode1(o1,o2,root1+1,root1+root2,0,root2-1);
    //有右子树
    if(root2+1 < len2)Tree->rchild = FindRootNode1(o1,o2,root1+root2+1,len1-1,root2+1,len2-1);
    return Tree;
}

void Post_InOrder2Tree(){
    //o1是后序遍历序列 o2是中序遍历序列
}

void Level_InOrder2Tree(){
    //o1是层次遍历序列 o2是中序遍历序列
}

int main(){
    // char o1[MAXSIZE],o2[MAXSIZE];
    // int len1,len2;
    // getOrder(o1,o2,len1,len2);
    char o1[] = {'A','B','D','G','E','C','F','\0'};
    char o2[] = {'D','G','B','E','A','F','C','\0'};
    BTree Tree = Pre_InOrder2Tree(o1,o2);
    PrintTree(Tree,0,0);
    return 0;
}


void printStrArray(char *s,int len){
    for(int i = 0 ; i < len; i ++){cout<<s[i]<<" ";}
    cout<<endl;
}

void getOrder(char *o1,char *o2){
    char t1[MAXSIZE],t2[MAXSIZE];
    cout<<"Enter your first traversal sequence:"<<endl;
    gets(t1);
    cout<<"Then the second first traversal sequence:"<<endl;
    gets(t2);
    int index = 0;
    for(int i = 0 ; i < strlen(t1);i++) if(t1[i] != ' ')o1[index++]=t1[i];
    index=0;
    for(int i = 0 ; i < strlen(t2);i++) if(t2[i] != ' ')o2[index++]=t2[i];
    cout<<o1<<endl;
    cout<<o2<<endl;
}
/*最后输出
Create Node A
Create Node B
Create Node D
Create Node G
Create Node E
Create Node C
Create Node F
        / C
                \ F
A
                / E
        \ B
                        / G
                \ D
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

