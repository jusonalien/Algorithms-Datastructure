////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-11 11:15:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int find_cycle(int n)
{
    int length=0;
    if(n==1) return ++length;
    while(n!=1)
    {
    if(n%2==0) {n/=2;++length;}
    else {n=3*n+1;++length;}
    }
    return ++length;
}
int main()
{
    int i,j;
    while(cin>>i>>j)
    {
        int max=0;
      if(i<=j)
        {
            for(int k=i;k<=j;k++)
          if(max<find_cycle(k))
            max=find_cycle(k);
        }
      else
      {
            for(int k=j;k<=i;k++)
          if(max<find_cycle(k))
            max=find_cycle(k);
      }
      cout<<i<<" "<<j<<" "<<max<<endl;
    }
    return 0;
}