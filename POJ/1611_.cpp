#include <iostream>
using namespace std;

#define MAXN 30000
int father[MAXN],rank[MAXN];

void Init(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		father[i]=i;
		rank[i]=1;
	}
}

int Find_Set(int x)
{
	if(x!=father[x])
	{
		father[x]=Find_Set(father[x]);
	}
	return father[x];
}

void Union(int x,int y)
{
	x=Find_Set(x);
	y=Find_Set(y);
	if(x==y)return;
	if(rank[x]>=rank[y])
	{
		father[y]=x;
		rank[x]=rank[x]+rank[y];
	}else
	{
		father[x]=y;
		rank[y]=rank[y]+rank[x];
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,first,next;
	int i,j;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)break;
		Init(n);
	
		for(i=0;i<m;i++)
		{
			cin>>k>>first;
			for(j=1;j<k;j++)
			{
				cin>>next;
				Union(first,next);
			}
		}
		cout<<rank[father[0]]<<endl;
	}
	return 0;
}
