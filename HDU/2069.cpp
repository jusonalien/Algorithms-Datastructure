////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:24:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:444KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int n;
const int MAXN = 400;
int dp[110][MAXN] = {0};
int coin[] = {1,5,10,25,50};
int main()
{
    dp[0][0] = 1;
            for(int i = 0;i < 5;i++){
            for(int j = 1;j <= 100;j++){
                for(int k = coin[i];k <= 300;k++)
                    dp[j][k] += dp[j - 1][k - coin[i]];
            }
        }
    while(~scanf("%d",&n)){
    int sum = 0;
    for(int i = 0;i <= 100;i++)
        sum += dp[i][n];
    cout<<sum<<endl;
    }
    return 0;
}