////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:19:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:480KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: B_敌兵布阵.cpp
	> Author:jusonalien 
	> Mail:jusonalien@qq.com 
	> Created Time: 2014年08月12日 星期二 19时27分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAXN = 50099;
int c[MAXN];
int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x]; x -= lowbit(x);
    }
    return ret;
}
void add(int x,int val){
    while(x <= MAXN){
        c[x] += val; x += lowbit(x);
    }
}
void sub(int x,int val){
    while(x <= MAXN){
        c[x] -= val; x += lowbit(x);
    }
}
int main(){
    int t,n,a;
    char ope[20];
    cin>>t;
    for(int k = 1;k <= t;k++){
        printf("Case %d:\n",k);
        memset(c,0,sizeof(c));
        cin>>n;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&a);add(i,a);
            }
        while(1){
            scanf("%s",ope);int x,y;
            if(ope[0] == 'E'){
                break;
            }else if(ope[0] == 'Q'){
               scanf("%d%d",&x,&y);
               if(x == 1)
                printf("%d\n",sum(y));
               else 
               printf("%d\n",sum(y) - sum(x-1));
            }else if(ope[0] == 'A'){
                scanf("%d%d",&x,&y);
                add(x,y);
            }else if(ope[0] == 'S'){
                scanf("%d%d",&x,&y);
                sub(x,y);
            }
        }
    }
    return 0;
}