#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int maxn = 5010;
LL p[maxn],dp[maxn][maxn],s[maxn];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++){
        cin>>s[i]; s[i] += s[i-1];
    }
    for(int i = m;i <= n;++i)
        for(int j = 1;j <= k;j++)
        dp[i][j] = max(dp[i-m][j-1] + s[i] - s[i - m],dp[i-1][j]);
    cout<<dp[n][k]<<endl;
}
