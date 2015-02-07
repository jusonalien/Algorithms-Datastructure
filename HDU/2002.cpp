////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-18 22:36:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
const double pi=3.1415927;
int main()
{
    double r;
    while(scanf("%lf",&r)!=EOF){
      printf("%.3f\n",(double)4/3*pi*r*r*r);
    }
    return 0;
}