#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1111;
int dp[maxn][maxn];
char a[maxn],b[maxn];
int solve(){
    int A = strlen(a);
    int B = strlen(b);
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= A;++i)
    for(int j = 1;j <= B;++j){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[A][B];
}
int main(){
    while(gets(a)&&gets(b)){
    printf("%d\n",solve());
    }
    return 0;
}
