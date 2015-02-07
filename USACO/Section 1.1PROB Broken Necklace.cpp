/*
ID: jusonal1
PROG: beads
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
char beads[1000];
int n;
int judge(int i) {
    if(i < 1) return n;
    else if(i > n) return 1;
    else return i;
}
int find_(int i) {
    int left = judge(i);
    int right = judge(i+1);
    int s_left = judge(i);
    int s_right = judge(i+1);
    int Left = judge(i);
    int Right = judge(i+1);
    int MAX = 0;
    while(beads[left] == beads[s_left]||beads[left] == 'w') {
        ++MAX;
        if(beads[s_left] == 'w') s_left = judge(--s_left);
        left = judge(--left);
        if(left == Right) return MAX+1;
    }

    while(beads[right] == beads[s_right]||beads[right] == 'w') {
        ++MAX;
        if(beads[s_right] == 'w') s_right = judge(++s_right);
        right = judge(++right);
        if(left == right) return MAX+1;
    }
    return MAX;
}
int main () {
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) scanf(" %c",&beads[i]);
    int ans = 0;
    for(int i = 1;i <= n;++i) {
        ans = max(ans,find_(i));
    }
    printf("%d\n",ans);
    return 0;
}