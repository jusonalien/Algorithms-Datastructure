#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
 
const int maxn = 191111;//最大点数
const int maxe = maxn*20;//最大边数
int head[maxn];//记录点的头
int to[maxe],cost[maxe],next[maxe];//记录边的两边断点，边长；
 
int n,m,st,ed,ecnt;//点数，边数，起始点，结束点，边数记录
 
void init() {//初始化
    memset(head,0,sizeof(head));
    ecnt = 1;
}
void add_edge(int u,int v,int c) {//添加边，姿势类似于链表的添加，是单向边，如果 是无向边的话要反向添加一次边
    to[ecnt] = v;cost[ecnt] = c;next[ecnt] = head[u];head[u] =ecnt++;
}
LL dis[maxn];//每个点到起始点的最短距离
bool vis[maxn];//记录该点是否在更新当中的队列中
 
void SPFA() {
    memset(dis,0x3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> que; que.push(st);
    dis[st] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = false;
        for(int p = head[u];p;p = next[p]) {
            int &v = to[p];
            if(dis[v]==-1||dis[v] > dis[u] + cost[p]) {
                    dis[v] = dis[u] + cost[p];
                    if(!vis[v]) que.push(v);//如果不在更新队列中，将该点加入
                    vis[v] = true;//加入更新队列当中
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    init();
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    SPFA();
    printf("%d\n",dis[ed]);
    return 0;
}