////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-30 11:39:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:1140MS
////Run memory:2360KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 111111;
int Q,C;
int sum[maxn<<2];
int col[maxn<<2];
void PushUp(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m){
    if(col[rt]){
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = col[rt]*(m - (m>>1));
        sum[rt<<1|1] = col[rt]*(m>>1);
        col[rt] = 0;
    }
}
void build(int l,int r,int rt){
    col[rt] = 0;
    sum[rt] = 1;
    if(l == r) return;
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
    return ;
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l&&R >= r){
        col[rt] = c;
        sum[rt] = (r - l + 1)*c;
        return;
    }
    int m = (l + r)>>1;
    PushDown(rt,r - l + 1);
    if(L <= m) update(L,R,c,lson);
    if(R > m)  update(L,R,c,rson);
    PushUp(rt);
    return ;
}
int main(){
    int c,n,q;
    scanf("%d",&c);
    int cas = 1;
    int a,b,u;
    while(c--){
        scanf("%d%d",&n,&q);
        build(1,n,1);
        for(int i = 1;i <= q;i++) {
            scanf("%d%d%d",&a,&b,&u);
            update(a,b,u,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas++,sum[1]);
    }
    return 0;
}
