//HDU 4911
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 100;
const int INF = 0x3f3f3f3f;
LL L[MAXN],R[MAXN],A[MAXN];
LL cou;
void Merge(LL p,LL q,LL r){
    LL i,j,k,n1,n2;
    n1 = q - p + 1;
    n2 = r - q;
    for(i = 1;i <= n1;i++) L[i] = A[p + i - 1];
    for(i = 1;i <= n2;i++) R[i] = A[q + i    ];
    L[n1 + 1] = R[n2 + 1] = INF;
    i = j = 1;
    for(k = p;k <= r;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
            cou += n1 - i + 1;//¼ÆÊý
        }
    }
    return ;
}
void MergeSort(LL p,LL r){
    LL q;
    if(p < r){
        q = (p + r)>>1;
        MergeSort(p,q);
        MergeSort(q + 1,r);
        Merge(p,q,r);
    }
    return ;
}
int main()
{
    LL n,t;
    while(~scanf("%I64d%I64d",&n,&t)){
        cou = 0LL;
        for(int i = 1;i <= n;i++) scanf("%I64d",&A[i]);
        MergeSort(1,n);
        printf("%I64d\n",max(0LL,cou - t));
    }
    return 0;
}