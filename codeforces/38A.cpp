#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;
int s[110];
int k;
int n;
int a,b;
int main()
{
    cin>>n;
    memset(s,0,sizeof(s));
    for(int i = 1;i < n;i++) {
        cin>>k;
        s[i + 1] = s[i] + k;
    }
    cin>>a>>b;
    cout<<s[b] - s[a]<<endl;
    return 0;
}

