////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-11 19:00:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4857
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:2464KB
//////////////////System Comment End//////////////////
/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
Origin:
*********************************/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 33333;
int T,n,m,k;
vector<int>G[maxn];
int v[maxn],ans[maxn];
void init(int n_){
    k = 1;
    memset(v,0,sizeof(v));
    memset(ans,0,sizeof(ans));
    for(int i_ = 1;i_ <= n_;++i_)
        G[i_].clear();
}
void get(int m_){
    int a_,b_;
    for(int i_ = 1;i_ <= m_;++i_){
        scanf("%d%d",&a_,&b_);
        v[a_]++;
        G[b_].push_back(a_);
    }
    return ;
}
void toposort(){
    priority_queue<int>Q;
    for(int i = 1;i <= n;++i){
        if(v[i] == 0)
            Q.push(i);
    }
    while(!Q.empty()){
        int t = Q.top();
        Q.pop();
        int size_ = G[t].size();
        for(int i = 0;i < size_;++i){
            v[G[t][i]]--;
            if(v[G[t][i]] == 0)
                Q.push(G[t][i]);
        }
        ans[k++] = t;
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        init(n);
        get(m);
        toposort();
        for(int i = n;i >= 1;--i){
            printf("%d",ans[i]);
            if(i != 1)printf(" ");
        }
        puts("");
    }
    return 0;
}
