////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-06-19 14:40:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:388KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 6;
const int MAX_M = 6;
int visit[MAX_N][MAX_M];//0没被搜过 1 安装碉堡 2 安装墙壁
int n,i,j,nmax,cou;
int Find(int x,int y)
{
    for(i = x;i <= n;i++)
    {
        if(visit[i][y] == 1) return 0;
        if(visit[i][y] == 2) break;
    }
    for(i = x;i >= 1;i--)
    {
        if(visit[i][y] == 1) return 0;
        if(visit[i][y] == 2) break;
    }
    for(i = y;i <= n;i++)
    {
        if(visit[x][i] == 1) return 0;
        if(visit[x][i] == 2) break;
    }
    for(i = y;i >= 1;i--)
    {
        if(visit[x][i] == 1) return 0;
        if(visit[x][i] == 2) break;
    }
    return 1;
}
void dfs()
{
    if( cou > nmax )
        nmax = cou;
    for(int k = 1;k <= n;k++)
      for(int l = 1;l <= n;l++)
      {
            if( !visit[k][l] && Find(k,l) )
            {
                visit[k][l] = 1;
                ++cou;
                dfs();
                visit[k][l] = 0;
                --cou;
            }
      }
}
int main()
{
    string str;
    while(cin >> n && n)
    {
        nmax = 0; cou = 0;
        for(int s = 1;s <= n;s++)
        {
            cin >> str;
            for(int o = 0;o < n; o++)
                visit[s][o+1] = (str[o] == 'X'? 2:0);
        }
        dfs();
        cout<<nmax<<endl;
    }
    return 0;
}