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

using namespace std;
int dp(int m,int n) {
    if(m==0||n==1) return 1;
    if(m < n) return dp(m,m);
    else return (dp(m-n,n) + dp(m,n-1));
}
int main(){
    int m,n,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&m,&n);
        printf("%d\n",dp(m,n));
    }
    return 0;
