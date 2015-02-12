#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100100];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    int energy = 0;
    int MIN = 0x3f3f3f3f;
    for(int i = 1;i < n;i++) {
    energy += a[i] - a[i+1];
    MIN = min(MIN,energy);
    }
    if(MIN >= 0)cout<<a[1];
    else cout<<a[1] - MIN;
    return 0;
}
