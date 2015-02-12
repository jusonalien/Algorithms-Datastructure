#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
int a[maxn];

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= m;++i) scanf("%d",&a[i]);
        sort(a+1,a+1+m);
        int ans = 1111111;
        for(int i = 1;i <= m - n+1;++i)
            ans = min(ans,a[i+n-1]-a[i]);
        printf("%d\n",ans);
    }
    return 0;
}
