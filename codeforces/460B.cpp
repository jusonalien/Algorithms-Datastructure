#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;
const int INf = 0x3f3f3f3f;
inline int f(int n){
    int q = 0;
    while(n){
        q += n % 10;
        n = n /10;
    }
    return q;
}
int main(){
    int a,b,c,pos;
    long long res,ans[MAXN],d;
    while(~scanf("%d%d%d",&a,&b,&c)){
            pos = 0;
        for(int i = 1;i <= 90;i++){
                long long  d = b;//С�ı�int
            for(int j = 1;j <= a;j++) {d*=i;}
                res = d + c;//cout<<res<<endl;
            if(f(res)==i&&res < 1e9) {
                ans[pos++] = res;
            }
        }
         cout<<pos<<endl;
        for(int i = 0;i < pos;i++) {
            cout<<ans[i];if(i<pos - 1)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
