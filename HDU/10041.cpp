////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-21 23:18:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:392KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int n;
    string color;
    map<string,int> ballon;
    while(cin>>n&&n)
    {
        ballon.clear();
        while(n--)
        {
            cin>>color;
            ballon[color]++;
        }
        map<string,int>::iterator it;
        int MAX = 0;
        string pos;
        for(it = ballon.begin();it != ballon.end();it++)
        {
            if(it->second > MAX)
            {
                MAX = it->second;
                pos = it->first;
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}