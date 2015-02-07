/*
ID: jusonal1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <stack>
using namespace std;
const int END = 2147483647;
char BASE[21] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
string base_change(int k,int base){
    string res;
    while(k){
        int input = k % base;
        k = k / base;
        res += BASE[input];
    }
    return res;
}
string change(string k){
    string ans;
    for(int i = k.length()-1;i >=0;i--)
        ans += k[i];
    return ans;
}
bool judge(string k){
    int n = k.length();
    int l = 0,r = n-1;
    while((l != r)&&((l-r)!=1)){
        if(k[l++] != k[r--]) return false;
    }
    return true;
}
int main () {
    int N,S;
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%d%d",&N,&S);
    int cnt = 0;
    for(int i = S+1;i <= END;++i) {
        if(cnt == N) break;
        int flag = 0;
        for(int j = 2;j <= 10;++j) {
            string input = base_change(i,j);
            if(judge(input)) ++flag;
            if(flag == 2) {printf("%d\n",i);++cnt;break;}
        }
    }
    return 0;
}