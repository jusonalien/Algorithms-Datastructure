#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 10010;
vector<int> G[MAXN];
int root;
int n;
int father[MAXN];
int depth[MAXN];
void dfs(int v,int p,int d){
    depth[v]  = d;
    for(int i = 0;i < G[v].size();i++){
        if(G[v][i] != p) dfs(G[v][i],v,d + 1);
    }
}
int lca(int u,int v){
    while(depth[u] > depth[v]) u = father[u];
    while(depth[v] > depth[u]) v = father[v];
    while(u != v){
        u = father[u];
        v = father[v];
    }
    return u;
}
int main(){
    int cas;
    cin>>cas;
    while(cas--){
        cin>>n;
        memset(father,-1,sizeof(father));
        for(int i = 1;i <= n;i++) G[i].clear();
        for(int i = 1;i < n;i++){
            int f,c;scanf("%d%d",&f,&c);
            father[c] = f;
            G[f].push_back(c);
        }
        for(int i = 1;i <= n;i++) {if(father[i] == -1) root = i;}
        dfs(root,-1,0);
        int a,b;cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}
