#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 3*100000 + 100;
struct node{
    int val;
    int pos;
};
int cmp_1(const node& a,const node& b){
    return a.val < b.val;
}
int cmp_2(const node& a,const node& b){
    return a.pos < b.pos;
}
node a[MAXN];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i].val);
            a[i].pos = i;
        }
        sort(a + 1,a + 1 + n,cmp_1);
        for(int i = 2;i <= n;i++){
            if(a[i].val <= a[i - 1].val)
                a[i].val = a[i-1].val + 1;
        }
        sort(a + 1,a + 1 + n,cmp_2);
        for(int i = 1;i <= n;i++){printf("%d",a[i].val);if(i < n) printf(" ");}
        cout<<endl;
    }
    return 0;
}
