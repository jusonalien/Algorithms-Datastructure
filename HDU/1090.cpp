////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-19 16:03:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:336KB
//////////////////System Comment End//////////////////

#include<iostream>
using namespace std;
int main()
{
    int a[100],n,c,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c>>d;a[i]=c+d;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}