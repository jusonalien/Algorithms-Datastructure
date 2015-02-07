////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-24 17:10:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin: HDU 3486
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int t,n,m;
int scores[110][110];
int a[110];
int dp[110][110];
void solve(){
    if(a[1] != -1)
        for(int i = 1;i <= m;++i){
            if(i != a[1])
                dp[1][i] = -1;
        }
        for(int i = 2;i <= n;i++){
            if(a[i] == -1){
                for(int j = 1;j <= m;++j)
                    for(int k = 1;k <= m;++k)
                    if(dp[i-1][k] != -1)
                        dp[i][j] = max(dp[i][j],dp[i-1][k]+scores[k][j]);
            }
            else{
                for(int j = 1;j <= m;++j)
                    if(dp[i-1][j] != -1)
                        dp[i][a[i]] = max(dp[i][a[i]],dp[i-1][j]+scores[j][a[i]]);
                for(int k = 1;k <= m;++k)
                    if(k != a[i])
                        dp[i][k] = -1;
            }
        }
        int ans = 0;
        for(int i = 1;i <= m;++i)
            ans = max(ans,dp[n][i]);
        printf("%d\n",ans);
}
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= m;j++) scanf("%d",&scores[i][j]);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
