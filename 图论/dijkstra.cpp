#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define typec int
const long long  INF = 9999999999999;
const int maxn = 1e6 + 50;
int  cost[maxn];
long long dist[maxn];
int e,pnt[maxn],nxt[maxn],head[maxn],prev[maxn],vis[maxn];
struct qnode{
    int v,c;
    qnode(int vv = 0,int cc = 0) : v(vv),c(cc) {}
    bool operator < (const qnode& r) const {return c > r.c;}
};
void dijkstra(int n,const int src){ //n  crc 是开始点
    qnode mv;
    int i,j,k,pre;
    priority_queue<qnode> que;
    vis[src] = 1;dist[src] = 0;
    que.push(qnode(src,0));
    for(pre = src,i = 1;i < n;i++){
        for(j = head[pre];j != -1;j = nxt[j]){
            k = pnt[j];
            if(vis[k] == 0&&dist[pre] + cost[j] < dist[k]){
                dist[k] = dist[pre] + cost[j];
                que.push(qnode(pnt[j],dist[k]));
                prev[k] = pre;
            }
        }
            while(!que.empty()&&vis[que.top().v] == 1)
                que.pop();
            if(que.empty()) break;
            mv = que.top();que.pop();
            vis[pre = mv.v] = 1;
        }
    }
    inline void addeadge(int u,int v,int c){
        pnt[e] = v;cost[e] = c;nxt[e] = head[u];head[u] = e++;
    }
void init(int nv,int ne){//nv 点的数目 ne 边的数目
    int i,u,v,c;
    e = 0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(prev,-1,sizeof(prev));
    fill(dist,dist + nv + 1,INF);
    for(int i = 0;i < ne;i++){
        scanf("%d%d%d",&u,&v,&c);
        addeadge(u,v,c);
        addeadge(v,u,c);
    }
}
void print(int cur){
    if(cur != 1){
        print(prev[cur]);
        printf(" %d",cur);
    }else if(cur == 1){
        printf("1");
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        init(n,m);
        dijkstra(n,1);
        if(dist[n] >= INF) puts("-1");
        else{
           print(n);puts("");
        }
    }
    return 0;
}
