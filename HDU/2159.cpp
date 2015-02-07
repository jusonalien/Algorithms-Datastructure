////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-31 12:52:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
int n,m,k,s,a,b;
int dp[150][150];
void completepack(int a,int b){
    for(int i = 1;i <= s;i++)
    for(int j = b;j <= m;j++){
        dp[i][j] = max(dp[i][j],dp[i - 1][j - b] + a);
    }
    return;
}

int main(){
    while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= k;i++){
            scanf("%d%d",&a,&b);
            completepack(a,b);
        }
        int res = -1;
        for(int i = 1;i <= s;i++)
            for(int j = 1;j <= m;j++){
                if(dp[i][j] >= n){
                    if(res < m - j) res = m - j;
                }
            }
        printf("%d\n",res);
    }
}
