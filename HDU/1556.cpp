////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:17:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 50;
int c[maxn],n;
int lowbit(int x){
    return x & (-x);
}
void add(int x,int val){
    while(x <= n){
        c[x] += val;
        x += lowbit(x);
    }
}
int sum(int x){
    int res = 0;
    while(x > 0){
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int main(){
    int a,b;
    while(~scanf("%d",&n)&&n){
        memset(c,0,sizeof(c));
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&a,&b);
            add(a,1);add(b+1,-1);
        }
        for(int i = 1;i < n;i++)cout<<sum(i)<<" ";
        cout<<sum(n)<<endl;
    }
    return 0;
}