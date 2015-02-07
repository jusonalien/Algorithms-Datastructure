////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-25 15:43:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5023
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:16020KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 1001111;
set<int> ans;
int SIZE;
int sum[maxn<<2];
void PushDown(int rt){
    if(sum[rt]){
        sum[rt<<1] = sum[rt];
        sum[rt<<1|1] = sum[rt];
        sum[rt] = 0;
    }
}
void build(int l,int r,int rt){
    if(l == r){
        sum[rt] = 2;return;
    }
    int m = (l + r) >>1;
    build(lson);
    build(rson);
    return ;
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l&&r <= R){
        sum[rt] = c;
        return ;
    }
    int m = (l + r)>>1;
    PushDown(rt);
    if(L <= m) update(L,R,c,lson);

    if(m <  R) update(L,R,c,rson);
    return ;
}
void query(int L,int R,int l,int r,int rt){
    //if(rt > SIZE) return;
    if(L <= l&&r <= R&&sum[rt]){
        ans.insert(sum[rt]);
        return ;
    }
    PushDown(rt);
    int m = (l + r)>>1;
    if(L <= m) query( L, R,lson);
    if(m <  R) query( L, R,rson);
    return;
}
void print(){
    set<int>::iterator it;
    it = ans.begin();
    cout<<*it;
    ans.erase(it);
    for(it = ans.begin();it != ans.end();++it)
        printf(" %d",*it);
        puts("");
}
void print_debug(){
    cout<<"sum: "<<endl;
    for(int i = 1;i <= 20;i++)
        cout<<sum[i]<<" ";
        puts("");
}
int main(){
    int N,Q,a,b,c;
    char ope[3];
    while(~scanf("%d%d",&N,&Q)&&(N+Q)){
        SIZE = (N+1)*N/2;
        memset(sum,0,sizeof(sum));
        build(1,N,1);
        while(Q--){
            scanf("%s",ope);
            if(ope[0] == 'Q'){
                scanf("%d%d",&a,&b);
                ans.clear();
                query(a,b,1,N,1);
                print();
            }else{
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c,1,N,1);
                //print_debug();
            }
        }
    }
    return 0;
}
