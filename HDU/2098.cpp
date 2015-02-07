////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:28:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int prime[10100];
void init(){
    fill(prime,prime + 10050,1);
    prime[1] = 0;
    //for(int i = 1;i <= 100;i++) cout<<prime[i]<<endl;
    for(int i = 2;i <= 10050;i++){
        if(!prime[i]) continue;
        for(int j = i*i,k = i;j <= 10050;j =i*(++k))
            prime[j] = 0;
    }
}
int main()
{
    init();
    /*for(int i = 1;i <= 100;i++){
        if(prime[i])cout<<i<<endl;
    }*/
    int cou,n;
    while(scanf("%d",&n)&&n){
        cou = 0;
        for(int i = 1;i < n/2;i++){
            if(prime[i]&&prime[n - i]) ++cou;
        }
        printf("%d\n",cou);
    }
    return 0;
}