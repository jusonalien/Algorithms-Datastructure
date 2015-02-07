////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-22 20:49:50
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[10010];

    scanf("%d",&n);
    while(n--)
    {
        int sum=1,flag=0;
        memset(a,'\0',sizeof(a));
        scanf("%s",a);
        for(i=1; i<=strlen(a); i++)
        {
            if(flag==0&&a[i]!=a[i-1])
                printf("%c",a[i-1]);
            else if(flag==1&&a[i]!=a[i-1])
                flag=0,printf("%d%c",sum,a[i-1]),sum=1;
            else
            {
                sum++;
                flag=1;
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}