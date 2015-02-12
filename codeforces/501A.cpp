#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int f(int p,int t) {
    return max(3*p/10,p-p*t/250);
}
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int M = f(a,c);
    int V = f(b,d);
    if(M < V) puts("Vasya");
    else if(M > V) puts("Misha");
    else puts("Tie");
    return 0;
}
