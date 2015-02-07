////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-11-02 14:01:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5086
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
const int Z=1000000007;
int datanum,i;
long long n,m,t,x,y,ans;
int main()
{
    scanf("%d",&datanum);//int
    while(datanum--)
    {
        scanf("%I64d",&n);
        m=n+1;
        ans=0;
        for(i=1;i<=n;i++)
        {
            t=(m-i)*i%Z;//long long
            scanf("%I64d",&x);
            y=(x*t)%Z;
            ans=(ans+y)%Z;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}