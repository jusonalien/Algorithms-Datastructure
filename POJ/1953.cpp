#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;
const int INf = 0x3f3f3f3f;
int dp[MAXN];
int main(){
    int n,t;
    cin>>n;
    dp[1] = 2,dp[2] = 3;
    for(int i = 3;i <= 50;i++) dp[i] = dp[i-1] + dp[i-2];
    for(int i = 1;i <= n;i++){
        scanf("%d",&t);
        printf("Scenario #%d:\n",i);
        printf("%d\n",dp[t]);
        if(i < n)cout<<endl;
    }
    return 0;
}
