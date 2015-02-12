#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAX_N = 110;
int N,M;
char field[MAX_N][MAX_N];
void dfs(int x,int y) {
    field[x][y] = '*';
    for(int dx = -1;dx <= 1;dx++)
    for(int dy = -1;dy <= 1;dy++) {
        int nx = x + dx;
        int ny = y + dy;
        if(nx >= 1&&nx <= M&&ny >= 1&&ny <= N&&field[nx][ny] == 'W')
            dfs(nx,ny);
    }
    return ;
}
void solve() {
    int res = 0;
    for(int i = 1;i <= M;i++)
    for(int j = 1;j <= N;j++) {
        if(field[i][j] == 'W') {
            dfs(i,j);
            res++;
        }
    }
    cout<<res<<endl;
}
int main()
{
    while(cin>>M>>N&&M){
    char s[110];
    for(int i = 1;i <= M;i++) {
        scanf("%s",&s);
        for(int j = 0;s[j] != '\0';j++)
            field[i][j + 1] = s[j];
    }
    solve();
    }
    return 0;
}
