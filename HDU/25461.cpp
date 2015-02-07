////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-28 23:46:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int dp[MAXN];
int v[MAXN];
int n,m;
int MAX;
int flag;
void solve(){
    for(int i = 0;i < n - 1;i++){
    for(int j = m - 5;j >= v[i];j--){
        dp[j] = max(dp[j],dp[j - v[i]]+ v[i]);
      }
    }
    cout<<m - dp[m - 5] - MAX<<endl;
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