////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-11-21 17:07:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5024
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:352KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 111;
char mp[maxn][maxn];
int n;
int zhi_x[] = {1,-1,0,0};
int zhi_y[] = {0,0,1,-1};
int xie_x[] = {1,1,-1,-1};
int xie_y[] = {-1,1,1,-1};
int get_max(int x,int y) {
    int MAX = 0;
    int b[8] = {0};
    int j = -1;
    for(int i = 0;i < 4;++i) {
        b[++j] = 1;
        int dx = x + zhi_x[i];
        int dy = y + zhi_y[i];
        for(;;dx += zhi_x[i],dy+=zhi_y[i]) {
            if(mp[dx][dy] == '.') b[j]++;
            else break;
        }
    }
    for(int i = 0;i < 4;++i) {
        b[++j] = 1;
        int dx = x + xie_x[i];
        int dy = y + xie_y[i];
        for(;;dx+=xie_x[i],dy+=xie_y[i]) {
            if(mp[dx][dy] == '.') b[j]++;
            else break;
        }
    }
    for(int i = 0;i < 4;++i) {
        for(int j = 0;j < 4;++j) {
            if(i!=j) MAX = max(MAX,b[i]+b[j]);
        }
    }
    for(int i = 4;i < 8;++i) {
        for(int j = 4;j < 8;++j) {
            if(i!=j) MAX = max(MAX,b[i]+b[j]);
        }
    }
    return MAX - 1;
}
void get_map() {
    for(int i = 0;i <= n+1;i++)
        for(int j = 0;j <= n+1;j++) mp[i][j] = '#';
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j) scanf(" %c",&mp[i][j]);
}
void get_ans() {
    int ans = 0;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j) if(mp[i][j] == '.')ans = max(ans,get_max(i,j));
    printf("%d\n",ans);
}
int main() {
    while(scanf("%d",&n)&&n) {
        get_map();
        get_ans();
    }
    return 0;
}
