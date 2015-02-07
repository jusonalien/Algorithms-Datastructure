#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 40;
int f[maxn][maxn];
int X,Y,K,B;
void init() {
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    for(int i = 1;i <= 31;++i) {
        f[i][0] = f[i-1][0];
        for(int j = 1;j <= i;++j)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
}
int calc(int x,int k) {
    int tot = 0,ans = 0;
    for(int i = 31;i > 0;--i) {
        if(x&(1<<i)) {
            ++tot;
            if(tot > k) break;
            x = x ^(1<<i);
        }
        if ( 1<<(i-1) <= x) {
            ans += f[i-1][k-tot];
        }
    }
    if(tot+x == k) ++ans;
    return ans;
}
int to_binary(int n,int b) {
    int ret = 0,d[40],i,j,m=0;
    while(n>0) {
        d[m++] = n % b;
        n /= b;
    }
    for(i = m-1;i >= 0;--i) {
        if(d[i] > 1) {
            for(j = i;j >= 0;--j)
                ret |= (1<<j);
            break;
        }
        else {
            ret |= (d[i]<<i);
        }
    }
    return ret;
}
int main()
{
    init();
    while(~scanf("%d%d%d%d",&X,&Y,&K,&B)) {
        printf("%d\n",calc(to_binary(Y,B),K) - calc(to_binary(X-1,B),K));
    }
    return 0;
}
