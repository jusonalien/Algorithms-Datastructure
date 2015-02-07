////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-27 17:34:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5053
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:332KB
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
inline long long sum(long long n){
    return (n*(n+1))*(n*(n+1))/4;
}
int main(){
    long long t,a,b;
    cin>>t;
    for(int i = 1;i <= t;i++){
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d: %I64d\n",i,sum(b) - sum(a-1));
    }
    return 0;
}
