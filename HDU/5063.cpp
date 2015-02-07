////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-11 23:02:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5063
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:940KB
//////////////////System Comment End//////////////////
/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin:
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
const int MOD = 1e9 + 7;
int n,m,pow;
stack<int> op;
int pow3(int a,int b)
{
    int r=1,base=a;
    while(b!=0)
    {
        if(b&1)
        r=(r*base)%MOD;
        base*=base;
        b>>=1;
    }
    return r;
}
inline int fun_1(int o){
    if(n&1){//&#198;&#230;¨ºy
        if(o <= (n+1)/2)
            return o*2 - 1;
        else
            return (o - (n+1)/2)*2;
    }else{//&#197;&#188;¨ºy
       if(o <= n/2)
            return o*2 - 1;
        else
            return (o - n/2) * 2;
    }
}
inline int fun_2(int o){
    return n - o + 1;
}
inline int solve(int o,int q){
    if(o == 1)
        return fun_1(q);
    else
        return fun_2(q);
}
int query(int o){
    stack<int> q = op;
    while(!q.empty()){
        o = solve(q.top(),o);
        q.pop();
    }
    long long ans = o;
    for(int i = 1;i <= pow;++i)
        ans = (ans*ans)%MOD;
    return ans;
}
int T;
int main(){
    n = 5;
    char ope[3];
    int ope_;
    cin>>T;
    while(T--){
        pow = 0;
        while(!op.empty()) op.pop();
        scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;++i){
            scanf("%s %d",ope,&ope_);
            if(ope[0] == 'O'&&ope_ != 3)
                    op.push(ope_);
            else if(ope[0] == 'O'&&ope_ == 3 )
                    pow++;
            else if(ope[0] == 'Q')
                 cout<<query(ope_)<<endl;
        }
    }
    return 0;
}
