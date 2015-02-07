////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-05-18 19:58:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:332KB
//////////////////System Comment End//////////////////

#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        if(n>=0&&n<=59) cout<<"E"<<endl;
        else if(n>=60&&n<=69) cout<<"D\n";
        else if(n>=70&&n<=79)  cout<<"C\n";
        else if(n>=80&&n<=89) cout<<"B\n";
        else if(n>=90&&n<=100) cout<<"A\n";
        else cout<<"Score is error!"<<endl;
    }
    return 0;
}
