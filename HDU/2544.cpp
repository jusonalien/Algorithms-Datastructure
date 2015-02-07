////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:23:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
const int MAXN = 150;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int d[MAXN],vis[MAXN];
void dijkstra(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = cost[1][i];
    vis[1] = 1;
    for(int i = 1;i < n;i++){
        int tmp = INF;int pos = 1;
        for(int j = 1;j <= n;j++){
            if(vis[j]) continue;
            if(tmp > d[j]){
                tmp = d[j];pos = j;
            }
        }
        vis[pos] = 1;
        for(int j = 1;j <= n;j++){
            if(vis[j]) continue;
            d[j] = min(d[j],d[pos] + cost[pos][j]);
        }
    }
}
int main()
{
    while(cin>>n>>m&&(n+m)){
       memset(cost,0x3f,sizeof(cost));
       int a,b,c;
       while(m--){
        scanf("%d%d%d",&a,&b,&c);
        cost[a][b] = cost[b][a] = c;
        cost[a][a] = cost[b][b] = 0;
       }
        dijkstra();
        cout<<d[n]<<endl;
    }
    return 0;
}