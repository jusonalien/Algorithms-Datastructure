#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int MAXN = 1000 + 50;
const long long MOD  = 1e9 + 7;
long long f[MAXN][MAXN];
long long sum[MAXN][MAXN];
char s[MAXN];
int main()
{
    while(~scanf("%s",s)){
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        f[0][0] = 1LL;
        int n = strlen(s);
        for(int i = 1;i <= n;i++) sum[0][i] = 1LL;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i + 1;j++){
                if(s[i-1] == 'I'||s[i-1] == '?'){
                    f[i][j] += sum[i-1][j-1];
                }
                if(s[i-1] == 'D'||s[i-1] == '?'){
                    f[i][j] += (sum[i-1][i] - sum[i-1][j-1]);
                    f[i][j] = (f[i][j] + MOD) % MOD;
                }
                sum[i][j] = (sum[i][j-1] + f[i][j]) % MOD;
            }
        }
        cout<<sum[n][n+1]<<endl;
    }
    return 0;
}
