////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-10-11 23:10:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
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
using namespace std;
int ans[7] = {1,9,18,54,90,174,258};
int T;
int main(){
    cin>>T;
    int k;
    while(T--){
        cin>>k;
        printf("%d\n",ans[k]);
    }
    return 0;
}