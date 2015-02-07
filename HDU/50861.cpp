////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-11-02 14:04:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5086
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MOD = 1000000007;
const int maxn = 477000;
int sum[maxn];
int add[maxn];
int main(){
    long long t,n;
    scanf("%I64d",&t);
    while(t--){
        long long k;
        long long ans = 0;
        scanf("%I64d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%I64d",&k);
            long long fuck = (i*(n-i+1))%MOD;
            long long m = (fuck*k) %MOD;
            ans = (ans + m)%MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}