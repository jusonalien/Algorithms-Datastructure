////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-26 16:09:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 110;
int n,m;
int father[MAXN];
struct node
{
    int x,y;
    int dis;
};
int cmp(const node& a,const node& b)
{
    return a.dis < b.dis;
}
node a[MAXN*3];
int Find(int x)
{
   if(x != father[x]) father[x] = Find(father[x]);
   return father[x];
}
void Merge(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
    {
        father[a] = b;
    }
    return ;
}
void solve()
{
    int res = 0,side = 0;;
    for(int i = 1;i <= m;i++)
    {
        father[i] = i;
    }
    sort(a,a + n,cmp);
   /* for(int i = 0;i < n ;i++)
        cout<<a[i].dis<<endl;*/
    for(int i = 0;i < n;i++)
    {
        int A = Find(a[i].x);
        int B = Find(a[i].y);
        if(A != B)
        {
            Merge(A,B);
            res += a[i].dis;
            side++;
        }
    }
    if(side < m - 1) puts("?");
    else  printf("%d\n",res);
}
int main()
{
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(int i = 0;i < n;i++)
           {
               cin>>a[i].x>>a[i].y>>a[i].dis;
           }
        solve();
    }
    return 0;
}