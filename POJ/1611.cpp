#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int MAX_N = 300000;
int father[MAX_N],weight[MAX_N];
int Find(int x){
    if(x != father[x]) father[x] = Find(father[x]);
    return father[x];
}
void init(int n){
    for(int i = 0;i < n;i++){
        father[i] = i;
        weight[i] = 1;
    }
}
void Merge(int x,int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return ;
    if(weight[x] >= weight[y]){
        father[y] = x;
        weight[x] += weight[y];
    }else {
        father[x] = y;
        weight[y] += weight[x];
    }
    return;
}
int main()
{
    int n,m;
    //freopen("in.txt","r",stdin);
    while(scanf(" %d%d",&n,&m)!= EOF&&(n + m)) {
         init(n);
         for(int i = 0;i < m;i++) {
            int k,first,next;
            scanf(" %d%d",&k,&first);
            for(int j = 0;j < k - 1;j++) {
                scanf(" %d",&next);
                Merge(first,next);
            }
         }
         printf("%d\n",weight[father[0]]);
    }
    return 0;
}
