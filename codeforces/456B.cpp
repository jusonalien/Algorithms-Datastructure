#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
string num;
int mod[] = {4,0,0,0};
int main()
{
    int sum = 0;
    cin>>num;
    for(int i = 0;num[i] ;i++){
        sum = sum * 10 + num[i] - '0';
        if(sum >= 4) sum = sum % 4;
    }
    cout<<mod[sum]<<endl;
    return 0;
}
