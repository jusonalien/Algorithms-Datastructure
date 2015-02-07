////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-06-15 16:27:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:892KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n;
const int MAX = 10010;
string clo[MAX];
pair<string,int> c[MAX];
int main()
{
    while(cin>>n&&n)
    {
        int t=1,flag = 1, m = 1;
        for(int i = 1;i<=n;i++)
            cin>>clo[i];
        for(int i = 1;i<=n;i++)
            c[i].second = 0;
            c[1].first = clo[1];
        for(int i = 1;i<=n;i++)
            {
                for(int j = 1;j<=t;j++)
                {
                    if(c[j].first == clo[i]) {++(c[j].second);break;flag = 0;}
                }
                if(flag) {c[++t].first = clo[i];flag = 1;}
            }
            int index = 1;
        for(int i = 1;i<=t;i++)
            if( c[i].second > m ){ m = c[i].second; index = i;};
            cout<<c[index].first<<endl;
    }
    return 0;
}
