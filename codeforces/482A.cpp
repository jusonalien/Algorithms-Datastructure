#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 111111;
int n,k;
int ans[maxn];
void solve() {
    ans[1] = 1;
    int flag = -1;
    int cre = n - 1;
    for(int i = 2;i <= k;++i) {
        flag *= -1;
        ans[i] = ans[i-1]+flag*(cre--);
    }
    flag *= -1;
    for(int i = k+1;i <= n;++i) {
        ans[i] = ans[i-1] +flag;
    }
    for(int i = 1;i <= n;++i) {
        if(i == n) printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }
}
int main() {

    while(cin>>n>>k) {
        solve();
    }
    return 0;
}
