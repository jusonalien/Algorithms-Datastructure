#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll rt<<1
#define rr rt<<1|1
#define lson l,m,ll
#define rson m+1,r,rr
const int INF = 1111111;
const int maxn = 55555;
int MAX[maxn<<2],MIN[maxn<<2];
void PushUp(int rt) {
    MAX[rt] = max(MAX[ll],MAX[rr]);
    MIN[rt] = min(MIN[ll],MIN[rr]);
}
void build(int l,int r,int rt) {
    if(l == r) {
        scanf("%d",&MAX[rt]);
        MIN[rt] = MAX[rt];
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query_max(int L,int R,int l,int r,int rt) {
    if(L <= l&&r <= R) {
        return MAX[rt];
    }
    int m = (l + r)>>1;
    int ans = 0;
    if(L <= m) ans = max(ans,query_max(L,R,lson));
    if(R > m)  ans = max(ans,query_max(L,R,rson));
    return ans;
}
int query_min(int L,int R,int l,int r,int rt) {
    if(L <= l&&r <= R) {
        return MIN[rt];
    }
    int m = (l + r)>>1;
    int ans = INF;
    if(L <= m) ans = min(ans,query_min(L,R,lson));
    if(m < R) ans = min(ans,query_min(L,R,rson));
    return ans;
}

int main() {
    int n,q,ql,qr;
    scanf("%d%d",&n,&q);
    build(1,n,1);
    while(q--) {
        scanf("%d%d",&ql,&qr);
        int ans = query_max(ql,qr,1,n,1) - query_min(ql,qr,1,n,1);
        printf("%d\n",ans);
    }
    return 0;
}
