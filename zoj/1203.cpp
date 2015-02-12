/*之前提交的这一份代码 又手贱将double 和float混用了 看来不是姿势问题
并且也为scanf 加上了~ 符号  看来不能随随便便加上这些东西=.=*/
#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 110;
const double INF = 0x3f3f3f3f;
int n;
struct node{
    double x;
    double y;
};
node Node[MAXN];
double cost(const node& a,const node& b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double mincost[MAXN];
int vis[MAXN];
double prim(){
    for(int i = 0;i < n;i++){
        mincost[i] = INF;
        vis[i] = 0;
    }
    mincost[0] = 0;
    double res = 0;
    while(1){
        int v = -1;
        for(int u = 0;u < n;u++)
            if(!vis[u]&&(v == -1||mincost[u] < mincost[v])) v = u;
        if(v == -1) break;
        vis[v] = 1;
        res += mincost[v];
        for(int u = 0;u < n;u++)
            mincost[u] = min(mincost[u],cost(Node[u],Node[v]));
    }
    return res;
}
int main()
{
        int t = 1;
   while(scanf("%d",&n)&&n){
        for(int i = 0;i < n;i++)
            scanf("%lf%lf",&Node[i].x,&Node[i].y);
        if(t > 1) puts("");
        printf("Case #%d:\n",t++);
        printf("The minimal distance is: %.2lf\n",prim());
   }
    return 0;
}
