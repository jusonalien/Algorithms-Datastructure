////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-23 23:38:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:10304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
const int MAX_N = 10000010;
struct node{
    int x;
    int y;
    node(int x,int y):x(x),y(y) {}
};
bool vis[MAX_N];
int father[MAX_N];
int weight[MAX_N];
int Find(int i) {
    if(i != father[i]) father[i] = Find(father[i]);
    return father[i];
}
void init(int i) {
    father[i] = i;
    weight[i] = 1;
}
void Merge(int a,int b) {
    int A = Find(a);
    int B = Find(b);
    if(A != B)
    if(weight[A] >= weight[B]){
        father[B] = A;
        weight[A] += weight[B];
    }else{
        father[A] = B;
        weight[B] += weight[A];
    }
}
vector<node> tree;
int main() {
    //freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)) {
        memset(vis,0,sizeof(vis));
        int MAX = 0;
        if(!n) {puts("1");continue;}
        while(n--){
            int i,j;
            scanf("%d%d",&i,&j);
            if(!vis[i]){vis[i] = 1;init(i);}
            if(!vis[j]){vis[j] = 1;init(j);}
            Merge(i,j);
            MAX = max(weight[father[i]],weight[father[j]]);
        }
        printf("%d\n",MAX);
    }
    return 0;
}
