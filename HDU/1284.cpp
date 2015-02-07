////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:26:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 33000;
int dp[MAXN];
int main(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=3;i++)
        for(int j=i;j<=MAXN;j++){
            //cout<<dp[j]<<endl;
            dp[j]+=dp[j-i];
        }
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",dp[n]);
    }
    return 0;
}