////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:24:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2147
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        if(n%2==0||m%2==0) puts("Wonderful!");
        else puts("What a pity!");
    }
    return 0;
}