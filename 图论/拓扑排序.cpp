#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 30017
int n, m;
int i, j, k;
int v[N],ans[N];
vector<int>P[N];
void init()
{
	memset(ans,0,sizeof(ans));
	memset(v,0,sizeof(v));
}
void Topsort()
{
	priority_queue<int>Q;
	int size, t;
	for(i = 1; i <= n; i++)
	{
		if(v[i] == 0)
			Q.push(i);
	}
	while(!Q.empty())
	{
		t = Q.top();
		Q.pop();
		size = P[t].size();
		for(i = 0; i < size; i++)//相关联的入度减1
		{
			v[P[t][i]]--;
			if(v[P[t][i]] == 0)
				Q.push(P[t][i]);
		}
		ans[k++] = t;
	}
}
int main()
{
	int T;
	int a, b;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(i = 1; i <= n; i++)//清空
		{
			P[i].clear();
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d%d",&a,&b);
			v[a]++;
			P[b].push_back(a);//逆向建图，在b后面添加a
		}
		k = 0;
		Topsort();
		for(i = n-1; i > 0; i--)//逆向输出
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[0]);
	}
	return 0;
}

/*
1
5 10
3 5
1 4
2 5
1 2
3 4
1 4
2 3
1 5
3 5
1 2
*/