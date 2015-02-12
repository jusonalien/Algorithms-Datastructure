#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[50];
    int chest=0,biceps=0,backs=0;
    int n;
    cin>>n;
    for(int i = 1;i <= n;++i) cin>>a[i];
    for(int i = 1;i <= n;i += 3) chest += a[i];
    for(int i = 2;i <= n;i += 3) biceps += a[i];
    for(int i = 3;i <= n;i += 3) backs += a[i];
    int ans=0;
    ans = max(chest,biceps);
    ans = max(ans,backs);
    if(ans == chest) puts("chest");
    else if(ans == biceps) puts("biceps");
    else if(ans == backs) puts("back");
    return 0;
}

