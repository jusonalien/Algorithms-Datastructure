#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,p,q;
const int maxn = 250 * 250 +100;
const int INF = 0x3f3f3f3f;
int P[maxn],Q[maxn],g[maxn],A[maxn],d[maxn];
#define REP(i,n) for(int i = 1;i <= n;++i)
void Hash(int* a,int num_a,int* b,int num_b) { //num_a >= num_b
    int hash_[maxn] = {0};
    for(int i = 1;i <= num_a;++i) hash_[a[i]] = i;
    for(int i = 0;i < num_b;++i) A[i] = hash_[b[i]];
   // REP(i,n*n) printf("%d ",hash_[i]);puts("");
   // REP(i,num_a) printf("%d ",a[i]);puts("");
   // REP(i,num_b) printf("%d ",A[i]); puts("");
}
int solve(int num) { // number is the smaller between q and p;
    int ans = 0;
    if(p >= q) Hash(P,p,Q,q);
    else Hash(Q,q,P,p);
    for(int i = 1;i <= num;++i) g[i] = INF;
    for(int i = 0;i < num;++i) {
        int k = lower_bound(g+1,g+num+1,A[i]) - g;
        d[i] = k;
        ans = max(ans,d[i]);
        g[k] = A[i];
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    for(int j = 1;j <= t;++j) {
        scanf("%d%d%d",&n,&p,&q);
        ++p;++q;
        for(int i = 1;i <= p;++i) scanf("%d",&P[i]);
        for(int i = 1;i <= q;++i) scanf("%d",&Q[i]);
        if(p >= q) printf("Case %d: %d\n",j,solve(q));
        else printf("Case %d: %d\n",j,solve(p));
    }
}

