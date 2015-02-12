#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    int a1,a2,a3,a4,k,l;
    k = 2*min(n,m) - 1;
    if(n > m) {a1 = 1;a2 = 0;a3 = 1;a4 = 0;}
    else {a1 = 0; a2 = 1;a3 = 0;a4 = 1;}
    l = (int)abs(n - m);
    printf("%d\n",k + l);
    int i = 1,j = 1;
    while(k > 0) {
        printf("%d %d\n",i,j);
        i += a1;
        j += a2;
        k--;if(!k) break;
        printf("%d %d\n",i,j);
        i += a2;
        j += a1;
        k--;
    }
    i = j = min(n,m);
    while(l) {
        i += a3;
        j += a4;
        printf("%d %d\n",i,j);
        l--;
    }
    return 0;
}
