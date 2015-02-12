#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
char *people[6] = {"Howard","Sheldon","Leonard","Penny","Rajesh","Howard"};
int n;
int main()
{
    cin>>n;
    int t = (int) floor(log((float)n/5.0 + 1)/log(2));
    int k = (int)ceil(((int)n - 5*((int)pow(2,t)-1))/pow(2,t));
    cout<<people[k]<<endl;
    return 0;
}
