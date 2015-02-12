#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
long long d;
int main()
{
    cin>>n>>k;
    int answer = 0;
    while(n--) {
        int t = 0;
        scanf("%I64d",&d);
        while(d != 0){
            int m = d % 10;
            d  /= 10;
            if(m == 4||m == 7) ++t;
        }
        if(t <= k) ++answer;
    }
    cout<<answer<<endl;
    return 0;
}
