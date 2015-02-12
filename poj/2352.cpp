#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
const int MAXN = 19010;
const int MIX = 32001;
int n,x,y;
int c[MIX];
int a[MAXN];
int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x]; x -= lowbit(x);
    }
    return ret;
}
void add(int x,int d){
    while(x <= MIX){
        c[x] += d; x += lowbit(x);
    }
}
int main()
{
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
       for(int i = 0;i < n;i++){
            scanf("%d%d",&x,&y);
            ++a[sum(x+1)];
            add(x+1,1);
        }
        for(int i = 0;i < n;i++)
            printf("%d\n",a[i]);
    }
    return 0;
}
