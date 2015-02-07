/*
ID:jusonal1
PROG:combo
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int a1,a2,a3,b1,b2,b3;
int n;
bool judge_1(int a,int b) {
    if(fabs(a-b)<=2 || fabs(a-b) >= n - 2)
        return true;
    else return false;
}
bool judge(int a,int b,int c) {
    if((judge_1(a1,a)&&judge_1(a2,b)&&judge_1(a3,c))||
       (judge_1(b1,a)&&judge_1(b2,b)&&judge_1(b3,c)))
        return true;
    else return false;
}

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    scanf("%d%d%d",&a1,&a2,&a3);
    scanf("%d%d%d",&b1,&b2,&b3);
    int ans = 0;
    for(int i = 1;i <= n;++i)
    for(int j = 1;j <= n;++j)
    for(int k = 1;k <= n;++k) {
        if(judge(i,j,k)) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
