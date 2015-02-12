#include<iostream>do
#include <cstdio>
using namespace std;
int main()
{
    int k,d;
    while(cin>>k>>d) {
    if(d==0&&k>1) puts("No solution");
    else {
    printf("%d",d);
    k -= 1;
    while(k--)
        cout<<"0";
        puts("");
    }
    }
    return 0;
}

