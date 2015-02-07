////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-07 19:54:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int sum(int n);
int main()
{
   int n;
   while(cin>>n)
   {
      cout<<sum(n)<<endl<<endl;
   }
    return 0;
}
int sum(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    s+=i;
    return s;
}