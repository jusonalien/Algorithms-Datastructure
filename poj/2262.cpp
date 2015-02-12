#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
bool prime(int n){
    if(n == 1) return false;
    else if(n == 2) return true;
    for(int i = 2;i*i <= n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        for(int i = 3;i <= n/2;i+=2){
            if(prime(i)&&prime(n - i)){
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }
    }
    return 0;
}
