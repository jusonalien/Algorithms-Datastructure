////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-06-19 14:50:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int SIZE = 6;
int size;
int maxn,cur;
int field[SIZE][SIZE];
int Find(int x,int y){ 
    for(int i = x;i <= size;i++) {
        if(field[i][y] == 1) return 0;
        else if (field[i][y] == 2) break;
    }
    for(int i = x;i >= 1   ;i--) {
        if(field[i][y] == 1) return 0;
        else if (field[i][y] == 2) break;
    }
    for(int i = y;i <= size;i++) {
        if(field[x][i] == 1) return 0;
        else if (field[x][i] == 2 ) break;
    }
    for(int i = y;i >= 1   ;i--) {
        if(field[x][i] == 1) return 0;
        else if (field[x][i] == 2) break;
    }
    return 1;
}
void dfs ( ) {
    if(cur > maxn)
        maxn = cur;
    for(int k = 1;k <= size;k++)
        for(int h =1;h <= size;h++)
            if(!field[k][h] && Find(k,h))  {
                field[k][h] = 1;
                ++cur;
                dfs();
                field[k][h] = 0;
                --cur;
            }
}

int main()
{
    char str[10];
    while(cin>>size&&size){
        maxn = cur = 0;
        for(int i = 1;i <= size;i++) {
                scanf("%s",str);
            for(int j = 0;j < size;j++) {
                field[i][j+1] = (str[j] == '.'? 0 : 2);
            }
        }
      //  for(int i = 1;i <= size;i++) {
      //  for(int j = 1;j <= size;j++) {
      //      cout<<field[i][j];
      //  } cout<<endl;
      //  }
        dfs();
        cout<<maxn<<endl;
    }
    return 0;
}