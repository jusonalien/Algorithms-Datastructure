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

int main(){
    //freopen("in.txt","r",stdin);
    int a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    ans = max(ans,a+b+c);
    ans = max(ans,(a+b)*c);
    ans = max(ans,a*(b+c));
    ans = max(ans,a*b*c);
    cout<<ans<<endl;
    return 0;
}
