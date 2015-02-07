////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-07-23 11:25:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
using namespace std;
const int N =1010;
int father[N];
int n,m,i,j;

void init(){
    for(int i = 1;i <= n;i++) father[i] = i;
}
int Find(int x){
    int k = x;
    int j;
    while(father[k] != k)
        k = father[k];
    int i = x;
    while(i!= k){
        j = father[i];
        father[i] = k;
        i = j;
    }
    return k;
}
void Merge(int a,int b){
    int A = Find(a);
    int B = Find(b);
    if(A != B) father[A] = B;
}
int main(){
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)&&n) {
        int tmp = 0;
        init();
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&i,&j);
            Merge(i,j);
        }
        for(int i = 1;i <= n;i++)
        if(father[i] == i) ++tmp;
        printf("%d\n",tmp - 1);
   }
    return 0;
}