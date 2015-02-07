////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-31 18:12:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 1010;
int n;
int MAX;
int dp[MAXN];
int data[MAXN];
int main()
{
    while(~scanf("%d",&n)&&n){
        for(int i = 1;i <= n;i++) {scanf("%d",&data[i]);dp[i] = data[i];}
        MAX = data[1];
        for(int i = 2;i <= n;i++){
        for(int j = i -1;j >= 1;j--){
            if(data[i] > data[j]&&dp[i] < dp[j] + data[i])
                dp[i] = dp[j] + data[i];
        }
        MAX = max(MAX,dp[i]);
        }
        printf("%d\n",MAX);
    }
    return 0;
}