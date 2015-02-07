/*
ID: jusonal1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 5555;
int n,m;
struct farmer{
    int P,A;
    bool operator < (const farmer& a) const {
        return P < a.P;
    }
};
farmer shit[maxn];
int solve() {
    int cost = 0;
    int cnt = 0;
    sort(shit+1,shit+1+m);
    for(int i = 1;i <= m;++i) {
        if(cnt + shit[i].A < n) {
            cnt += shit[i].A;
            cost += shit[i].P * shit[i].A;
        }else {
            int extra = (cnt + shit[i].A) - n;
            cnt += (shit[i].A - extra);
            cost += (shit[i].A - extra)*shit[i].P;
            break;
        }
    }
    return cost;
}
int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);

    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= m;++i) scanf("%d%d",&shit[i].P,&shit[i].A);
        printf("%d\n",solve());
    }
    return 0;
}