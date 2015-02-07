/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin: HDU 3486
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 222222;
int k,n;
int A[maxn];
int d[maxn][30];
void RMQ_init() {
    for(int i = 1;i <= n;++i) d[i][0] = A[i];
    for(int j = 1;(1<<j) <= n;++j)
        for(int i = 1;i + (1 << j) - 1 <= n;++i)
            d[i][j] = max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R){
    int k = 0;
    while((1<<(k +1)) <= R - L +1) k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}
bool judge_1(int len,int t){
    int ans = 0;
    for(int i = 1;i <= t;i++ )
        ans += RMQ(1+len*(i-1),len*(i));//cout<<RMQ(i,i+q-1)<<endl;
    return ans > k;
}
void solve_1(){
    bool flag = 0;
    int l = 1,r = n,m ;
    int ans;
    while(l <= r){
        m = (l + r)>>1;
        if(judge_1(n/m,m)){
            ans = m;//out<<ans<<endl;
            r = m - 1;
        }
        else l = m + 1;
    }
    printf("%d\n",ans);
    return ;
}
bool judge_2(int len) {
    int ans = 0;
    int am = n /len;
    for(int i_ = 1;i_ <= (am-1)*len;i_ += len)
        ans += RMQ(i_,i_ + len - 1);
    return ans > k;
}
void solve_2() {
    int m = n>>1;
    int ans = 0;
    for(int i = m;i >= 1;--i){
        if(judge_2(i)){
            ans = i;break;
        }
    }
    printf("%d\n",n/ans);
    return ;
}
int main(){
    while(scanf("%d%d",&n,&k)&&!(n<0&&k<0)){
        memset(d,0,sizeof(d));
        int sum = 0;
        for(int i = 1;i <= n;++i) scanf("%d",&A[i]),sum += A[i];
        if(sum <= k) {puts("-1");continue;}
        RMQ_init();
        if(RMQ(1,n) > k) {puts("1");continue;}
        solve_2();
    }
    return 0;
}
/*
5 4
1 1 1 1 1
11 300
7 100 7 101 100 100 9 100 100 110 110
5 4
1 1 1 1 1
*/
