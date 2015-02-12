/*
这道题对于渣渣的，并且做题量很少的我来说具有一定的迷惑性，棋盘上的搜索给我的第一感觉
就是dfs，可是拍的dfs和bfs题目总数不超过6个目测的我还是悬崖勒马，悔过自新>。<
这几天一直在拍dfs和bfs，感觉多拍几下就会很有感觉了，这是真的！！！ from jusonalien~~
下午15:35，ps：各位做题的acmer啊  不要吝啬公开自己的代码哈~酱紫才方便我等渣渣的交流啊~
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
struct node{
    int x,y,step;
    node(int x,int y,int step):x(x),y(y),step(step) {}
};
const int MAX_N = 310;
int n;
int l;
int sx,sy,ex,ey;
const int dx[] = {-2,-1,1,2,2,1,-1,-2};
const int dy[] = {1,2,2,1,-1,-2,-2,-1};
int vis[MAX_N][MAX_N];
int MAX;
int res;
int step;
int ok(int x,int y) {
    return x >= 0&&x < l&&y >= 0&&y < l;
}
int bfs(int x,int y,int step) {
    queue<node> q;
    while(!q.empty()) q.pop();
    q.push(node(x,y,step));
    while(!q.empty()) {
    node que = q.front();
    q.pop();
    for(int i = 0;i < 8;i++) {
        int nx = que.x + dx[i];
        int ny = que.y + dy[i];
        if(!ok(nx,ny)||vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        if(nx == ex&&ny == ey) return que.step + 1;
        int k = que.step ;
        q.push(node(nx,ny,que.step + 1));
    }
    }
    return -1;
}
int main()
{
    scanf("%d",&n);
    while(n--) {
        memset(vis,0,sizeof(vis));
        scanf("%d",&l);
        scanf(" %d%d",&sx,&sy);
        scanf(" %d%d",&ex,&ey);
        if(sx == ex&&sy == ey) {cout<<"0"<<endl; continue;}
        printf("%d\n",bfs(sx,sy,0));
    }
    return 0;
}
