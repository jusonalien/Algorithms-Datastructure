////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-18 19:50:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2003
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////

#include<stdio.h>
int main()
{
    double  n;
    while(scanf("%lf",&n)!=EOF){
        if(n<0){
            n *= -1.0;
        }
        printf ("%.2f\n",n);
    }
    return 0;
}
