#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int ans = 0,n,p,q;
    cin>>n;
    while(n--){
        scanf("%d%d",&p,&q);
        if(q-p>=2)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
