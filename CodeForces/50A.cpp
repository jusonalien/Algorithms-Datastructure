#include <iostream>
using namespace std;
int a,b;


int main()
{
    while(cin>>a>>b) {
        if(b%2 == 0) cout<<a*b/2<<endl;
        else cout<<a*(b/2) + a/2<<endl;
    }
    return 0;
}
