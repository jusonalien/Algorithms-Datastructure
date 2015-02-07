////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-06-17 23:39:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int a,b,c;
    while(~scanf("%d%d",&a,&b))
    {
        b%=4;a%=10;c=a;
        if(b==0)
        b=4;
        while(--b)
        c=c*a%10;
        printf("%d\n",c);
    }
}