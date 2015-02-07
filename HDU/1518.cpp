////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:34:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:1015MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <string.h>
using namespace std;
int n;
int edge;
int m;
int a[25];
int vis[25];
int sum;
bool dfs(int start,int bianshu,int EDGE) { //bianshu [0,4] shengxia [m,0]
   if(EDGE == edge) {
     start = 0;EDGE = 0; if((++bianshu) == 4) return true;
   }
   for(int i = start;i < m;i++) {
    if(!vis[i]) {
        vis[i] = 1;
        if(EDGE + a[i] <= edge) {
            if(dfs(i + 1,bianshu,EDGE + a[i])) return true;
        }
        vis[i] = 0;
    }
   }
   return false;
}
int main() {
    cin>>n;
    while(n--) {
        scanf("%d",&m);
        sum = 0;
        memset(vis,0,sizeof(vis));
        for(int i =0;i < m;i++) {scanf("%d",&a[i]);sum += a[i];}
        edge = sum / 4;
        if(4*edge != sum) {puts("no");continue;};
        if(dfs(0,0,0)) puts("yes");
        else puts("no");
    }
    return 0;
}