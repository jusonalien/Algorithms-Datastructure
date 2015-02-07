////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-04 11:48:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
    int a,b,n,i;
    while(cin>>a>>b>>n&&!(a==0&&b==0&&n==0))
    {
        int f[1009];
        f[1]=1;
        f[2]=1;
        for(i=3;i<=1008;i++)
        {

            f[i]=(a*f[i-1]+b*f[i-2])%7;


        }
        cout<<f[(n-1)%1008+1]<<endl;
    }
    return 0;
}