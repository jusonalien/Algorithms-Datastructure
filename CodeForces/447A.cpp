#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
int p,n;
int k[310];
int P[310];
int main()
{
    cin>>p>>n;
    int flag1,flag2 = 0;
    memset(P,0,sizeof(P));
    for(int i = 0;i < n;i++) scanf("%d",&k[i]);
    for(int i = 0;i < n;i++) {
        if( P[k[i] % p] ) { flag1 = i + 1;flag2 = 1;break;}
        else P[k[i] % p] = 1;
    }
    if(!flag2) puts("-1\n");
    else cout<<flag1<<endl;
    return 0;
}
