/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin:
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>

using namespace std;
int dp(int m,int n) {
    if(m==0||n==1) return 1;
    if(m < n) return dp(m,m);
    else return (dp(m-n,n) + dp(m,n-1));
}
int DP[15][15];
void solve() {
    for(int i = 0;i <= 12;++i) DP[0][i] = 1;
    for(int i = 0;i <= 12;++i) DP[i][1] = 1;
    for(int i = 1;i <= 10;++i) {
        for(int j = 1;j <= 10;++j) {
            if(i < j) DP[i][j] = DP[i][i];
            else DP[i][j] = DP[i-j][j] + DP[i][j-1];
        }
    }
}
int main(){
    int m,n,t;
    solve();
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&m,&n);
        printf("%d\n",DP[m][n]);
    }
    return 0;
}
