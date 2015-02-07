////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:11:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4070
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1068KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
struct node{
    int d,t;
};
bool cmp(const node& a,const node& b){
    return a.t > b.t;
}
node bug[MAXN];
int main()
{
    int t,n,cas = 1;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&bug[i].d,&bug[i].t);
        sort(bug + 1,bug + 1 + n,cmp);
        int ans = 0,tmp,acum = 0;
        for(int i = 1;i <= n;i++){
            tmp = bug[i].d + bug[i].t + acum;
            if(ans < tmp) ans = tmp;
            acum += bug[i].d;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}