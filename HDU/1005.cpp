////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-18 13:57:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,n,t;
    while(scanf("%d %d %d",&a,&b,&n)!=EOF&&(a||b||n)){
            int s[53]={0};
         if(n==1||n==2) {cout<<1<<endl;continue;}
         s[1]=1;s[2]=1;
         a%=7;b%=7;
         for(int i=3;i<52;i++)
         {
             s[i]=(a*s[i-1]+b*s[i-2])%7;
             if(s[i]==1&&s[i-1]==1)
                { t=i; break; }
         }
         s[0]=s[t-2];
         cout<<s[n%(t-2)]<<endl;
    }
    return 0;
}