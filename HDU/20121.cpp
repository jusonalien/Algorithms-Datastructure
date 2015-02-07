////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-01 21:29:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*素数打表的一定要注意数组越界的问题，这个问题非常严峻，不管这个越界的数组的下标到底和问题的测试数据有半毛钱的关系
特么 oj就是赏你一个大大的WA，比如数据不可能达到3000的，假如我定义了一个prime[3000]的数组，如果循环过程如果越界到prime[3000]的话
你就乖乖地等着WA吧  哈哈哈哈哈哈*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int x,y,flag = 0;
int prime[3000];
int main()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= 2900;i++){
        if(prime[i]) continue;
        for(int j = i*i,k = i;j <= 2900;j =i*(++k))
            prime[j] = 1;
    }
    while(~scanf("%d%d",&x,&y)&&(x + y)){
    for(int i = x;i <= y;i++){
        if(prime[i*i + i + 41]){
                 flag = 1;break;
        }
    }
    if(flag) {puts("Sorry");flag = 0;}
    else puts("OK");
    }
    return 0;
}
