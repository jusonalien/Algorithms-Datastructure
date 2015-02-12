#include <iostream>
#include <cstdio>
using namespace std;
int f[1000000];
int main()
{
    f[0] = 0,f[1] = 1;
    int i,n;
    for( i = 2;!(f[i-1]==1&&f[i-2]==0&&i!=2);i++ )
       f[i] = (f[i-1] + f[i-2])%10000;
    int flag = i - 2;
    //cout<<f[flag]<<endl<<f[flag - 1]<<endl;
    while(~scanf("%d",&n)&&n!=-1){
        printf("%d\n",f[ n%flag ]);
    }
    return 0;
}
