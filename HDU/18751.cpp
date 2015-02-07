////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-26 19:23:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:384KB
//////////////////System Comment End//////////////////
/*这次的错误竟然是关于sqrt函数重载的问题额。。。。。。want cry no tears
  QAQ   以后要将sqrt里的东西装到一个新定义的变量里去才行！！不然很容易
  出错  刚刚在hdu那里提交的直接就是CE！！ 没错就是CE！！  可是为毛在vj上就是提示
  wa啊  真是DT！！！！又一个下午的时间因这些小问题给耽误了。。。*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const double INF = 999999999.0;
int father[MAXN];
int t,c;
double mp[MAXN][MAXN];
struct node
{
    int x,y;
};
node p[MAXN];
struct side
{
    int start,end;
    double dis;
};
int cmp(const side& a,const side& b)
{
    return a.dis < b.dis;
}
side Node[MAXN*MAXN/2];
int Find(int x)
{
    if(x != father[x]) father[x] = Find(father[x]);
    return father[x];
}
int Merge(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return 0;
    else father[a] = b;
    return 1;
}
void solve()
{
    double res = 0;
    int cur = 0;
    for(int i = 1;i <= c;i++)
        father[i] = i;
    for(int i = 1;i < c;i++)
        for(int j = i + 1;j <= c;j++)
        {
            int k = ((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
            if(k >= 100&&k <= 1000000)
            {
                int b =  cur;
                Node[b].start = i;
                Node[b].end   = j;
                Node[b].dis   = sqrt((double)k);
                cur++;
            }
        }
    sort(Node,Node + cur,cmp);
    int cou = 0;
    for(int i = 0;i < cur;i++)
    {
        if(Merge(Node[i].start,Node[i].end))
        {
            res += Node[i].dis;
            cou++;
        }
    }
    if(cou < c - 1)
    {
        cout<<"oh!"<<endl;
    }
    else
    {
        printf("%.1lf\n",res*100);
    }
   return ;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>c;
        for(int i = 1;i <= c;i++)
            cin>>p[i].x>>p[i].y;
        solve();
    }
    return 0;
}