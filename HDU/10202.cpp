////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-22 21:56:02
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
char a[10010];
int main()
{
    int n,i;
    scanf("%d",&n);
    while(n--){
        int sum=1;
        memset(a,'\0',sizeof(a));
        scanf("%s",a);
        for( i=1;i<=strlen(a);i++){
            if(sum==1&&a[i]!=a[i-1]) printf("%c",a[i-1]);
            else if(sum!=1&&a[i]!=a[i-1]){printf("%d%c",sum,a[i-1]);sum=1;}
            else ++sum;
        }
        printf("\n");
    }
    return 0;
}
