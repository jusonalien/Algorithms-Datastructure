#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 55;
int a[MAX];
int main()
{
    int n,k;
    while(cin>>n>>k){
    int t=0;
    for(int i=1;i<=n;i++)
       cin>>a[i];
        for(int i=1;a[i]&&a[i]>=a[k]&&i<=n;i++)
            ++t; cout<<t<<endl;
        }
    return 0;
}
