////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-22 21:22:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:3328MS
////Run memory:2356KB
//////////////////System Comment End//////////////////
/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 222222;
int MAX[maxn<<2];
int h,w,n;
inline void PushUp(int rt){
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);
}
void build(int l,int r,int rt){
    MAX[rt] = w;
    if(l == r) return;
    int m = (l + r)>>1;
    build(lson);
    build(rson);
}
int query(int c,int l,int r,int rt){
    if(l == r){
        MAX[rt] -= c;
        return l;
    }
    int m = (l + r)>>1;
    int res = (MAX[rt<<1] >= c)?query(c,lson):query(c,rson);
    PushUp(rt);
    return res;
}
int main(){
    while(~scanf("%d%d%d",&h,&w,&n)){
        if(h > n)h = n;
        build(1,h,1);
        while(n--){
            int c;
            scanf("%d",&c);
            if(MAX[1] < c) puts("-1");
            else printf("%d\n",query(c,1,h,1));
        }
    }
    return 0;
}