////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:15:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4027
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:4744KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MAXN = 410000;
LL sum[MAXN];
LL data[MAXN];
int isone[MAXN];//init
int n,m;
LL SQRT(LL x){
    return (LL)floor(sqrt(double(x)));
}
void build(int now,int l,int r){
    if(l == r){
        sum[now] = data[l];
        isone[now] = (sum[now] == r - l + 1);//判断这部分是否全部变成1
    }else{
        int m = (l + r) >> 1;
        build(now << 1,l,m);
        build((now << 1) + 1,m + 1,r);
        sum[now] = sum[now << 1] + sum[(now << 1) + 1];
        isone[now] = (sum[now] == r - l + 1);
    }
}

LL Sum(int now,int l,int r,int L,int R){
    if(l > R||r < L) return 0;
    if(L <= l&&r <= R) return sum[now];
    int m = (l + r) >> 1;
    return Sum(now << 1,l,m,L,R) + Sum((now << 1) + 1,m + 1,r,L,R);
}

void update(int now,int l,int r,int L,int R){
    if(l > R||r < L)return;
    if(isone[now]) return ;
    if(l == r){
        sum[now] = SQRT(sum[now]);
        isone[now] = (sum[now] == r - l + 1);
    }else{
        int m = (l + r)>>1;
        update(now<<1,l,m,L,R);
        update((now<<1)+1,m + 1,r,L,R);
        sum[now] = sum[now<<1] + sum[(now<<1) + 1];
        isone[now] = (sum[now] == r - l + 1);
    }
}
int main(){
    int cas = 1;
    int q,r,l;
    while(~scanf("%d",&n)){
        for(int i = 1;i <= n;i++) scanf("%I64d",&data[i]);
        build(1,1,n);
        memset(isone,0,sizeof(isone));
        scanf("%d",&m);
        printf("Case #%d:\n",cas++);
        for(int i = 1;i <= m;i++){
            scanf("%d%d%d",&q,&l,&r);
            if(l > r) {int tmp = l;l = r; r = tmp;}
            if(!q) update(1,1,n,l,r);
            else cout<<Sum(1,1,n,l,r)<<endl;
        }
        cout<<endl;
    }
    return 0;
}