/*
ID: jusonal1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int  leap_year[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int comom_year[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans[8];
int N;

bool is_leap(int year){
    if((year%100)==0&&(year%400)==0) return true;
    else if((year%100)!=0&&year%4==0) return true;
    else return false;
}

int main ()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    memset(ans,0,sizeof(ans));
    scanf("%d",&N);
    int flag = 1;
    for(int i = 1900;i <= 1900+N-1;++i){
        if(is_leap(i))
        for(int j = 1;j <= 12;++j){
            for(int k = 1;k <= leap_year[j];++k){
                if(flag == 8) flag = 1;
                if(k == 13){
                    ans[flag]++;
                }
                flag++;
            }
        }
        else
        for(int j = 1;j <= 12;++j){
            for(int k = 1;k <= comom_year[j];++k){
                if(flag == 8) flag = 1;
                if(k == 13){
                    ans[flag]++;
                }
                flag++;
            }
        }
    }
    printf("%d %d %d %d %d %d %d\n",ans[6],ans[7],ans[1],ans[2],ans[3],ans[4],ans[5]);
    return 0;
}
