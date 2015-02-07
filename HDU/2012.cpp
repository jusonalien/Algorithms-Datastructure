////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-01 21:14:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int x,y,flag = 0;
bool prime(int n){
    if(n==1||n==2)return true;
    for(int i = 2;i*i <= n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{

    while(~scanf("%d%d",&x,&y)&&(x + y)){
    for(int i = x;i <= y;i++){
        if(!prime(i*i + i + 41)){
                 flag = 1;break;
        }
    }
    if(flag) {puts("Sorry");flag = 0;}
    else puts("OK");
    }
    return 0;
}
