////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:20:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,c;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
int d[MAXN][MAXN];
void floyd(){
    for(int k = 0;k < n;k++)
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) {
                if(i == j)d[i][j] = 0;
                else d[i][j] = INF;
        }
        for(int i = 0;i < m;i++){
            int a,b;scanf("%d%d",&a,&b);
            d[a][b] = d[b][a] = 1;
        }
        floyd();
        int flag = 0;
        for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) if(d[i][j] > 7){
            flag = 1;break;
        }
        if(flag)puts("No");
        else puts("Yes");
    }
    return 0;
}