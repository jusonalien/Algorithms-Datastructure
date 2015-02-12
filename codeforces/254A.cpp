#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct card{
    int index;
    int number;
};
bool cmp(const card& a,const card& b){
    return a.number < b.number;
}
card a[1111111];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= 2*n;++i) {
        cin>>a[i].number;
        a[i].index = i;
    }
    int flag = 1;
    sort(a+1,a+1+2*n,cmp);
    for(int i = 1;i <= 2*n;i += 2) {
        if(a[i].number!=a[i+1].number){
            puts("-1");flag = 0;break;
        }
    }
    if(flag) {
        for(int i = 1;i <= 2*n;i+=2) {
            printf("%d %d\n",a[i].index,a[i+1].index);
        }
    }
    return 0;
}
