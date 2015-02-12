#include <cstdio>
#include <algorithm>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll rt<<1
#define rr rt<<1|1
const int maxn = 222222;
struct node{
    int id,value,num;
};
int n;
node get[maxn];
node sum[maxn<<2];
void PushUp(int rt) {
    sum[rt].num = sum[ll].num + sum[rr].num;
}
void build(int l,int r,int rt) {
    if(l == r) {
        sum[rt].num = 1;
        sum[rt].id = 0;
        sum[rt].value = 0;
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int id,int num,int value,int l,int r,int rt) {
    if(l == r) {
        sum[rt].value = value;
        sum[rt].num   = 0;
        sum[rt].id    = id;
        return ;
    }
    int m = (l + r)>>1;
    if(num <= sum[ll].num) update(id,num,value,lson);
    else update(id,num - sum[ll].num,value,rson);
    PushUp(rt);
}
int ans_num;
void print(int l,int r,int rt) { //i = 1;
    if(l == r&&ans_num == n) {
        printf("%d\n",get[sum[rt].id].value);
        return ;
    }else if(l == r) {
        printf("%d ",get[sum[rt].id].value);
        ans_num++;
        return ;
    }
    int m = (l + r) >> 1;
    print(lson);
    print(rson);
}
int main() {
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;++i) {
            scanf("%d%d",&get[i].num,&get[i].value);
            get[i].id = i;
        }
        build(1,n,1);
        //printf("%d\n",sum[1].num);
        for(int i = n;i >= 1;--i) {
            update(i,get[i].num+1,get[i].value,1,n,1);
        }
        ans_num = 1;
        print(1,n,1);
    }
    return 0;
}
