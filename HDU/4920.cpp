////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:10:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4920
////Problem Title: 
////Run result: Accept
////Run time:1703MS
////Run memory:7892KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 800 + 10;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];
int is_zero_a[MAXN];
int is_zero_b[MAXN];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(is_zero_a,0,sizeof(is_zero_a));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){scanf("%d",&a[i][j]);a[i][j] = a[i][j] % 3;
            if(a[i][j])is_zero_a[i] = 1;}
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){scanf("%d",&b[i][j]);b[i][j] = b[i][j] % 3;}
        memset(c,0,sizeof(c));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
              if(!a[i][j]) continue;
                for(int k = 1;k <= n;k++) c[i][k] =(c[i][k] + a[i][j] * b[j][k])% 3;
        }
        for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            printf("%d",c[i][j]);
            if(j < n) printf(" ");
            else puts("");
        }
    }
    return 0;
}