#include <cstdio>
#include <iostream>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
const int maxn = 111111;
long long sum[maxn<<2];
long long add[maxn<<2];
void PushUp(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (m - (m>>1))*add[rt];
        sum[rt<<1|1] += (m>>1)*add[rt];
        add[rt] = 0;
    }
}
void build(int l,int r,int rt){
    add[rt] = 0;
    if(l == r){
        scanf("%I64d",&sum[rt]);
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
    return ;
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l&&r <= R){
        add[rt] += c;
        sum[rt] += (LL)c * (r - l + 1);
        return;
    }
    PushDown(rt,r - l + 1);
    int m = (l + r) >>1;
    if(m >= L) update(L,R,c,lson);
    if(m < R)  update(L,R,c,rson);
    PushUp(rt);
    return ;
}
LL query(int L,int R,int l,int r,int rt){
    if(L <= l&&r <= R){
        return sum[rt];
    }
    LL res = 0LL;
    PushDown(rt,r - l + 1);
    int m = (l + r)>>1;
    if(L <= m) res += query(L,R,lson);
    if(m < R)  res += query(L,R,rson);
    return res;
}
int main(){
    int n,q;
    char ope[5];
    int a,b,c;
    while(~scanf("%d%d",&n,&q)){
        build(1,n,1);
        while(q--){
            scanf("%s",ope);
            if(ope[0] == 'Q'){
                scanf("%d%d",&a,&b);
                printf("%I64d\n",query(a,b,1,n,1));
            }else{
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c,1,n,1);
            }
        }
    }
    return 0;
}
