/*
ID: jusonal1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
const int maxn = 15;
int n;
struct MP{
    char mp[maxn][maxn];
};
MP orign_map;
MP then_map;
MP new_map;
bool pattern_1(const MP a){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            if(then_map.mp[i][j] != a.mp[n-j+1][i])
                return false;
    return true;
}
bool pattern_2(const MP a){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            if(then_map.mp[i][j] != a.mp[n-i+1][n-j+1])
                return false;
    return true;
}
bool pattern_3(MP a){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            if(then_map.mp[i][j] != a.mp[j][n-i+1])
                return false;
    return true;
}
bool pattern_4(MP a){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            if(then_map.mp[i][j] != a.mp[i][n-j+1])
                return false;
    return true;
}
bool pattern_5(MP a){
    if(pattern_1(a)) return true;
    if(pattern_2(a)) return true;
    if(pattern_3(a)) return true;
    return false;
}
bool pattern_6(MP a){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            if(a.mp[i][j] != then_map.mp[i][j]) return false;
    return true;
}
void print(){
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j)
            printf("%c",new_map.mp[i][j]);
            puts("");
    }
    puts("");
}
void getmap(){
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
        scanf(" %c",&orign_map.mp[i][j]);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
        scanf(" %c",&then_map.mp[i][j]);
    return ;
}
int main () {
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d",&n);
    getmap();
    MP new_map;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            new_map.mp[i][j] = orign_map.mp[i][n-j+1];
    if(pattern_1(orign_map)) puts("1");
    else if(pattern_2(orign_map)) puts("2");
    else if(pattern_3(orign_map)) puts("3");
    else if(pattern_4(orign_map)) puts("4");
    else if(pattern_5(new_map)) puts("5");
    else if(pattern_6(orign_map))puts("6");
    else puts("7");
    return 0;
}
