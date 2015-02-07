/*
ID: jusonal1
PROG: milk2
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
struct node{
    int left;
    int right;
    bool operator<(const node& T)const{
        return left < T.left;
    }
};
int n;
const int maxn = 5000 + 100;
node cow[maxn];
int main () {
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) scanf("%d%d",&cow[i].left,&cow[i].right);
    sort(cow + 1,cow + 1 + n);
    int cont_time = cow[1].right - cow[1].left,idle_time = 0;
    int start = 0,end = 0;
    int blank_sum = 0;
    start = cow[1].left;
    end   = cow[1].right;
    for(int i = 1;i <= n;++i){
        if(cow[i].left > end ){
            idle_time = max(idle_time,cow[i].left - end);
            start = cow[i].left;
            end   = cow[i].right;
        }
        else if(cow[i].right > end){
            end = cow[i].right;
        }
        cont_time = max(cont_time,end - start);
    }
    printf("%d %d\n",cont_time,idle_time);
    return 0;
}
