#include<iostream>
#include<cstring>
#include <cstdio>

using  namespace std;
const int MAXN  = 8000;
int dp[MAXN];
int coin[] = {1,5,10,25,50};
int main(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0;i < 5;i++)
        for(int j = coin[i];j < MAXN - 10;j++)
        dp[j] += dp[j - coin[i]];
    int k;
    while(~scanf("%d",&k)) cout<<dp[k]<<endl;
    return 0;
}
