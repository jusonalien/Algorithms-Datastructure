#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
	int value;
	struct BiTNode *lchild,*rchild;
}*BiTree;

bool LT(int a,int b)
{
	if(a<b)
		return true;
	else
		return false;
}
bool SearchBST(BiTree root,int data,BiTree f,BiTree &p)
{
	if(!root)
	{
		p=f;
		return false;
	}
	else if(data==root->value)
	{
		p=root;
		return true;
	}
	else if(data<root->value)
		return SearchBST(root->lchild,data,root,p);
	else if(data>root->value)
		return SearchBST(root->rchild,data,root,p);
}

inline void InsertBST(BiTree &root,int data)
{
	BiTree p,s;
	if(!SearchBST(root,data,NULL,p))
	{
		s=(struct BiTNode *)malloc(sizeof(BiTNode));
		s->value=data;
		s->lchild=s->rchild=NULL;
		if(p==NULL)
			root=s;
		else if(LT(data,p->value))
			p->lchild=s;
		else
			p->rchild=s;
	}
	return ;
}

int main(void)
{
	int i,a[101],n;
	BiTree root;
	int sea;
	while(scanf("%d",&n)!=EOF)
	{
		root=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			InsertBST(root,a[i]);
		}
        while(~scanf("%d",&sea)) {
                BiTree p;
            if(SearchBST(root, sea, NULL, p))
                printf("EXist!\n");
            else {
                printf("not exist! but I will help you to insert it!\n");
                InsertBST(root,sea);
            }
        }
	}
	return 0;
}