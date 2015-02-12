#include <iostream>
#include <cstdio>
using namespace std;
int abs(int x){
    if (x < 0) return -x;
    return x;
}
int main()
{
   int n;
   cin>>n;
   int d = n/2;
   for(int i = d;i >= -d;i--){
    for(int j = -d;j <= d;j++){
        if(abs(i) + abs(j) <= d) cout<<"D";
        else cout<<"*";
    }puts("");
   }
    return 0;
}
