#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n,s,x,y;
    cin>>n>>s;
    int ans = -1;
    while(n--){
        scanf("%d%d",&x,&y);
        if(x <= s&&y==0){ans = max(ans,0);continue;}
        if(x + 1 > s) continue;
        ans = max(ans,100-y);
    }
    cout<<ans<<endl;
    return 0;
}
