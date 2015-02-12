#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i = 1;i <= n;++i)
const int maxn = 22222;
int dragon[maxn],knight[maxn];
int n,m;
void solve() {
    sort(dragon+1,dragon+1+n);
    sort(knight+1,knight+1+m);
    int i = 1,j = 1;
    int coins = 0;
    for(;i <= n&&j <= m;) {
        if(dragon[i] <= knight[j]) {coins += knight[j];++i;++j;}
        else ++j;
    }
    if(i >= n) printf("%d\n",coins);
    else printf("Loowater is doomed!\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m)) {
        REP(i,n) scanf("%d",&dragon[i]);
        REP(i,m) scanf("%d",&knight[i]);
        solve();
    }
}

