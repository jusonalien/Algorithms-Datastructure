/*
ID: jusonal1
PROG: palsquare
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
int base;
int square[350];
char BASE[21] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
string base_change(int k){
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
    for(int i = 1;i <= 300;++i)
        square[i] = i*i;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d",&base);
    for(int i = 1;i <= 300;++i)
        if(judge(base_change(square[i])))
            cout<<change(base_change(i))<<" "<<change(base_change(square[i]))<<endl;
    return 0;
}
