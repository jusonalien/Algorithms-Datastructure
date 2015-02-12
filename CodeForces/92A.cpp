#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    int k = m % ((n+1)*n/2);
    int o = (int)floor((-1 + sqrt(1 + 8*k))/2);
    printf("%d\n",k - o*(o+1)/2);
    return 0;
}
