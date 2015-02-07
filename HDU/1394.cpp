////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-01 13:09:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 5555;
int c[maxn];
int a[maxn];
int n;
inline int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];x -= lowbit(x);
    }
    return ret;
}
void add(int x,int d){
    while(x <= n){
        c[x] += d;x += lowbit(x);
    }
}
int main(){
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        int ans = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            ans += i - 1 - sum(a[i]);
            add(a[i] + 1,1);
        }
        //cout<<ans<<endl;
        int MIN = ans;
        for(int i = 1;i <= n;i++){
            MIN += n - (a[i] + 1) - (a[i]);
            ans = min(MIN,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}