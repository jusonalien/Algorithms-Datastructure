#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i = 1;i <= n;++i)
const int maxn = 22222;
int n;
struct solid{
    int B,J;
    bool operator<(const solid& a)const{
        return J > a.J;
    }
};
solid s[maxn];
int  solve() {
    sort(s+1,s+1+n);
    s[0].B = s[0].J = 0;
    int ans = 0,S = 0;
    for(int i = 1;i <= n;++i) {
        S += s[i].B;
        ans = max(ans,S + s[i].J);
    }
    return ans;
}
int main()
{
    int cas = 1;
    while(scanf("%d",&n)&&n) {
        REP(i,n) scanf("%d%d",&s[i].B,&s[i].J);
        printf("Case %d: %d\n",cas++,solve());
    }
}
