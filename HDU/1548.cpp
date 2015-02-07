////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-07 19:03:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:568KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,s,e;
const int INF = 0x3f3f3f3f;
const int MAXN = 300;
int cost[MAXN][MAXN];
int d[MAXN],vis[MAXN];
void dijkstra(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = cost[s][i];
    vis[s] = 1;
    for(int i = 1;i < n;i++){
        int tmp = INF;int pos = s;
        for(int j = 1;j <= n;j++){
            if(vis[j]) continue;
            if(tmp > d[j]){
                tmp = d[j]; pos = j;
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
    while(cin>>n&&n){
        cin>>s>>e;
        int dis;
        for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) cost[i][j] = INF;
        for(int i = 1;i <= n;i++){
            scanf("%d",&dis);
            cost[i][i] = 0;
            if(i - dis >= 1) cost[i][i - dis] = 1;
            if(i + dis <= n) cost[i][i + dis] = 1;
        }
        dijkstra();
        if(d[e] >= INF) cout<<"-1"<<endl;
        else cout<<d[e]<<endl;
    }
    return 0;
}
