////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-08-28 17:45:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:2284KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1|1
const int MAXN = 200000 + 1000;
int n,m,a,b;
int max_node[MAXN<<2];
void PushUP(int rt){
    max_node[rt] = max(max_node[rt<<1],max_node[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l == r){
        scanf("%d",&max_node[rt]);return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        max_node[rt] = add;return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p,add,lson);
    else update(p,add,rson);
    PushUP(rt);
}
int query(int ql,int qr,int l,int r,int rt){
    if(ql <= l&&r <= qr){
        return max_node[rt];
    }
    int m = (l + r) >> 1;
    int MAX = 0;
    if(ql <= m) MAX = max(MAX,query(ql,qr,lson));
    if(qr > m)  MAX = max(MAX,query(ql,qr,rson));
    return MAX;
}
int main(){
    char ope[2];
    int a,b;
    while(~scanf("%d%d",&n,&m)){
        build(1,n,1);
        for(int i = 1;i <= m;i++){
            scanf("%s",ope);
            scanf("%d%d",&a,&b);
            if(ope[0] == 'Q')printf("%d\n",query(a,b,1,n,1));
            else update(a,b,1,n,1);
        }
    }
    return 0;
}
