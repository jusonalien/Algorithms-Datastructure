#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 100;
struct node{
    LL val;
    int pos;
};
node no[maxn];
LL  c[maxn];
int re[maxn],n;
bool cmp(const node &a,const node &b){
    return a.val < b.val;
}
int lowbit(int x){
    return x & (-x);
}
void add(int x,LL val){
    while(x <= n){
        c[x] += val;
        x += lowbit(x);
    }
}
LL sum(int x){
    LL res = 0;
    while(x > 0){
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int main(){
    LL ret,k;
    while(~scanf("%d%I64d",&n,&k)){
        for(int i = 1; i <= n; i++){
            scanf("%I64d",&no[i].val);
            no[i].pos = i;
        }
        sort(no+1,no+n+1,cmp);
        re[no[1].pos] = 1;
        for(int i = 2; i <= n; i++){
            if(no[i].val == no[i - 1].val) re[no[i].pos] = re[no[i-1].pos];
            else re[no[i].pos] = i;
        }
        memset(c,0,sizeof(c));
        ret = 0;
        for(int i = 1; i <= n; i++){
            ret += (i - sum(re[i]) - 1);
            add(re[i],1);
        }
       if(ret <= k) ret = 0;
       else ret -= k;
       cout<<ret<<endl;
    }
    return 0;
}