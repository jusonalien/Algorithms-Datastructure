/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年01月25日 星期日 00时22分34秒
 ************************************************************************/

#include<iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
char mp[4][4];
void getmp() {
    for(int i = 0;i < 4;++i)
    for(int j = 0;j < 4;++j) {
        scanf(" %c",&mp[i][j]);
    }
}
int judge(int i,int j) {
    int w = 0;
    int b = 0;
    mp[i][j] == '.'? ++w:++b;
    mp[i+1][j] == '.'?++w:++b;
    mp[i][j+1] == '.'?++w:++b;
    mp[i+1][j+1] == '.'?++w:++b;
    if(w==2&&b==2) return 0;
    else return 1;
}
int scan() {
    for(int i = 0;i < 3;++i)
    for(int j = 0;j < 3;++j) {
        if(judge(i,j)) return 1;
    }
    return 0;
}
int main() {
    getmp();
    if(scan()) puts("YES");
    else puts("NO");
    return 0;
}

