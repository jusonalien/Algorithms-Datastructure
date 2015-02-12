#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1010;
int n,m;
struct node
{
    int start,end;
    int dis;
};
node P[MAXN*20];
int cmp(const node& a,const node& b)
{
    return a.dis < b.dis;
}
int father[MAXN];
int Find(int x)
{
    int i = x;
    while(i != father[i])
        i = father[i];
    int  k = i;
    while(i != x)
    {
        x = father[x];
        father[x] = i;
    }
    return i;
}
int Merge(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if( a== b) return 0;
    else father[a] = b;
    return 1;
}
void solve()
{
    for(int i = 1;i <=n ;i++)
        father[i] = i;
    int res = 0,dis,cou = 0;
    for(int i = 0;i < m;i++)
        scanf("%d%d%d",&P[i].start,&P[i].end,&P[i].dis);
    sort(P,P + m,cmp);int tt = 0;
    for(int i = 0;i < m;i++)
    {
        if(Merge(P[i].start,P[i].end))
           {
            res += P[i].dis;
            tt++;
           }
    }
   if(tt < n - 1) puts("-1");
   else cout<<res<<endl;
   return;
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&n)
        solve();
    return 0;
}
