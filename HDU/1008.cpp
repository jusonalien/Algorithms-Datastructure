////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-10 21:53:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int laa(int k)
{
    return k>0?6:4;
}
int a[100];
int main()
{
    int n,k=0;
    while(cin>>n&&n)
    {
        int level=0;
       int  total=n*5;
       for(int i=0;i<n;i++)
        {cin>>a[i];total+=abs(level-a[i])*laa(a[i]-level);level=a[i];}
        cout<<total<<endl;
    }
    return 0;
}