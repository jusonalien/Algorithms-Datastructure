////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-16 20:10:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:372KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int W,H;
int sx,sy;
char field[25][25];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int res;
bool ok(int x,int y) {
    if(x>=1&&x <= H&&y >= 1&&y <= W&&(field[x][y] == '.'||field[x][y] == '@')) return true;
    else return false;
}
void dfs(int x,int y){
    field[x][y] = '#';
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i],ny = y + dy[i];
        if(ok(nx,ny)) {
        ++res;
        dfs(nx,ny);
        }
    }
    return ;
}


int main()
{
    while(cin>>W>>H&&(W||H)){
    for(int i =1;i <= H;i++) {
        char s[25]; scanf("%s",&s);
        for(int j = 0;s[j] != '\0';j++) {
            field[i][j + 1] = s[j];
            if(s[j] == '@')  {sx = i;sy = j + 1;}
        }
    }
    res = 1;
    dfs(sx,sy);
   // cout<<dfs(sx,sy)<<endl;
    cout<<res<<endl;
   }
    return 0;
}