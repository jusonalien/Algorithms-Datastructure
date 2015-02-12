#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i = 1;i <= n;++i)
const int maxn = 10;
char mp[maxn][maxn];
void get_mp() {
    REP(i,8)REP(j,8)scanf(" %c",&mp[i][j]);
}
int solve() {
    int ans = 0;
    REP(i,8) {
        int flag = 1;
        REP(j,8)if(mp[i][j] != 'B'){flag = 0;break;}
        if(flag)
        ++ans;
    }
    if(ans==8)return ans;
    REP(i,8) {
        int flag =1;
        REP(j,8)if(mp[j][i] != 'B'){flag = 0;break;}
        if(flag)
        ++ans;
    }
    return ans;
}
int main()
{
    get_mp();
    printf("%d\n",solve());
    return 0;
}
