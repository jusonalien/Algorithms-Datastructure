/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin:
*********************************/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1111;
int depth[maxn];
int father[maxn];
vector<int> G[maxn];
struct node{
    int v;
    int num;
    bool operator < (const node& a)const {
        return v < a.v;
    }
}V[maxn];
int root,n,q;
void init(){
    memset(father,-1,sizeof(father));
    memset(depth,0,sizeof(depth));
    for(int i = 0;i < maxn;++i) {
        V[i].num = 0;
        V[i].v   = i;
        G[i].clear();
    }
    return ;
}
void dfs(int v,int p,int d){
    depth[v] = d;
    for(int i = 0;i < G[v].size();++i){
        if(G[v][i] != p)
            dfs(G[v][i],v,d+1);
    }
    return ;
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
    while(~scanf("%d",&n)){
        init();
        for(int j = 1;j <= n;++j){
            int num_,node_;
            scanf("%d:(%d)",&node_,&num_);
            for(int k = 1;k <= num_;++k){
                int la;
                scanf("%d",&la);
                father[la] = node_;
                G[node_].push_back(la);
            }
        }
        for(int i = 1;i <= n;++i){
            if(father[i] == -1){
                root = i;break;
            }
        }
        dfs(root,-1,0);
        //int query;
        scanf("%d",&q);
        int a_,b_;
        for(int i_ = 1;i_ <= q;++i_){
            getchar();
            scanf("\t(%d\t %d\t)",&a_,&b_);
            V[lca(a_,b_)].num++;
        }
        sort(V + 1,V + n + 1);
        for(int i = 1;i <= n;++i){
            if(V[i].num != 0){
                printf("%d:%d",V[i].v,V[i].num);
                if(i != n) puts("");
            }
        }
    }
    return 0;
}
