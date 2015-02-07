////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:12:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4034
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
int a[MAXN][MAXN];
int b[MAXN][MAXN];//scanf
int n;
int edge;
void mst(){
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
            if(b[i][j] == b[i][k] + b[k][j]&&b[i][j]&&b[i][k]&&b[k][j])b[i][j] = 0;
            if(b[i][j] > b[i][k] + b[k][j]&&b[i][j]&&b[i][k]&&b[k][j]) {puts("impossible");return;}
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)if(b[i][j]) edge++;
    printf("%d\n",edge);
    return;
}
int main()
{
    int cas;
    cin>>cas;
    for(int i = 1;i <= cas;i++){
        edge = 0;
        cin>>n;
        for(int k = 1;k <= n;k++)
            for(int l = 1;l <= n;l++) scanf("%d",&b[k][l]);
        printf("Case %d: ",i);
        mst();
    }

    return 0;
}