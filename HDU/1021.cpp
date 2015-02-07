////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-18 11:36:21
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n%4==2)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
