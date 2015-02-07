////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-28 23:15:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:4340KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int dp[MAXN][MAXN];
int v[MAXN];
int n,m;
int MAX;
int flag;
void solve(){
    for(int i = 0;i < n - 1;i++){
    for(int j = 0;j <= m - 5;j++){
        if(j < v[i]) dp[i + 1][j] = dp[i][j];
        else dp[i + 1][j] = max(dp[i][j],dp[i][j - v[i]] + v[i]);
      }
    }
    cout<<m - dp[n - 1][m - 5] - MAX<<endl;
}
int main()
{
    while(~scanf("%d",&n)&&n){
            MAX = 0;
            memset(dp,0,sizeof(dp));
        for(int i = 0;i < n;i++){
            scanf("%d",&v[i]);
        }
        scanf("%d",&m);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        sort(v,v + n);
        MAX = v[n - 1];
        solve();
    }
    return 0;
}