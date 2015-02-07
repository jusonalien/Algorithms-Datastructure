/*
求连通图上割点的数目
O(V + N)
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 111;
vector<int> g[N];
int n, low[N], dfn[N], f[N];
bool vis[N];
//  dfn 记录节点的深度,f[i] >= 
void dfs(int u, int depth, const int &root) { //root为连通图的树根
    dfn[u] = low[u] = depth;
    vis[u] = true;
    int cnt = 0;
    for (int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
            cnt++;
            dfs(v, depth+1, root);
            low[u] = min(low[u], low[v]);
            if (u!=root && low[v]>=dfn[u]) f[u]++;   //当u不为树根的时候
            if (u==root && cnt>=2) f[u]++;           //当u为搜索树的树根的时候
        } else low[u] = min(low[u], dfn[v]);            //当为反向边的时候~~
    }
}

int cut_point() {
    dfs(1, 1, 1);
    int ans = 0;
    for (int i=1; i<=n; i++) if (f[i] >= 1) ans++;
    return ans;
}
void init() {
    memset(f, 0, sizeof(f));
    memset(vis, false, sizeof(vis));
    for(int i = 0;i < N;++i) g[i].clear();
}
int main() {
    while(scanf("%d",&n)&&n) {
        init();
        int start,v;
        while(scanf("%d",&start)&&start) {
            while(getchar()!='\n') {
                scanf("%d",&v);
                g[start].push_back(v);
                g[v].push_back(start);
            }
        }
        printf("%d\n",cut_point());
    }
    return 0;
}