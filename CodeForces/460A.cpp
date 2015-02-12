#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;
const int INf = 0x3f3f3f3f;
int main(){
    int n,m,tmp,res;
    while(~scanf("%d%d",&n,&m)){
        tmp = 0;
        res = n;
        while(n / m){
            tmp = n%m;
            n = n / m;
            res += n;
            n += tmp;
        }
        cout<<res;
    }
    return 0;
}
