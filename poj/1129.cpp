/*这一题刷的我心力焦脆~~~~实在想不通这题和bfs与dfs究竟有半毛钱的关系啊尼玛
结果就是一个超级麻烦的模拟和暴力！！！！*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAX_N = 30;
int mp[MAX_N][MAX_N];
int color[MAX_N][4];
int vis[27];
int n;
int MAX;
int flag;
char s[30];
int c_to_n(char c) {
    return c - 'A' + 1;
}
int main()
{
    while(~scanf("%d",&n)&&n) {
        flag = 0;
        MAX = 1;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        memset(color,0,sizeof(color));//0 没有赋值过这个颜色 1已经赋值过这个颜色 2 不能赋值这个颜色
        while(n--) {
            scanf("%s",s);
            if(strlen(s) > 2) {
                    vis[c_to_n(s[0])] = 1;
                for(int i = 2;s[i] != '\0';i++) {
                    mp[c_to_n(s[0])][c_to_n(s[i])] = 1;
                    mp[c_to_n(s[i])][c_to_n(s[0])] = 1;
                    vis[c_to_n(s[i])] = 1;
                }
            }
        }
            for(int i = 1;i <= MAX_N;i++) {
                if(!vis[i]) continue;
                for(int k = 0;k < 4;k++) {
                    if(color[i][k] == 0) {
                        color[i][k] = 1;MAX = max(MAX,k + 1);
                        for(int j = 1;j <= MAX_N;j++) if(mp[i][j]) color[j][k] = 2;
                        flag = 1;
                    }
                    else if(color[i][k] == 2) continue;
                    if(flag) {flag = 0;break;}
                }
            }
        if(MAX == 1) printf("1 channel needed.\n");
        else printf("%d channels needed.\n",MAX);
        }
    return 0;
}
