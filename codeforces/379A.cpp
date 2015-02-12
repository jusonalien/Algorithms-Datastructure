#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,ans,tmp;
    while(~scanf("%d%d",&a,&b)){
        ans = a;
        while(1){
            if(a/b==0) break;
            ans += a/b;
            tmp = a % b;
              a = a/b + tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}

