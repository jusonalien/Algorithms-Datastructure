////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:21:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:388KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,s,t;
const int INF = 0x3f3f3f3f;
const int MAXN = 250;
int cost[MAXN][MAXN];
int d[MAXN],vis[MAXN];
void dijkstra( ){
    fill(d,d + MAXN,INF);
    fill(vis,vis + MAXN,0);
    d[s+1] = 0;
    while(1){
        int v = -1;
        for(int i = 1;i <= n;i++){
            if(!vis[i]&&(v == -1||d[i] < d[v])) v = i;
        }
        if(v == -1) break;
        vis[v] = 1;
        for(int i = 1;i <= n;i++)
            d[i] = min(d[i],d[v] + cost[v][i]);
    }
    return ;
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++) cost[i][j] = INF;
        int a,b,x;
        for(int i = 1;i <= m;i++){
            scanf("%d%d%d",&a,&b,&x);
            if(x < cost[a+1][b+1])
            cost[a+1][b+1] = cost[b+1][a+1] = x;
        }
        scanf("%d%d",&s,&t);
        dijkstra();
        if(d[t+1] == INF) cout<<"-1"<<endl;
        else cout<<d[t+1]<<endl;
    }
    return 0;
}