#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
using namespace std;
string fin[2111];
int father[2111];
int flag[2111];
int num ;
int f(string a) {
    for(int i = 1;i <= num;++i)
        if(a == fin[i]) return i;
        ++num;
        fin[num] = a;
        return num;
}
int Find(int i) {
    while(i != father[i])
        i = father[i];
    return i;
}
void init() {
    num = 0;
    for(int i = 0;i < 2111;++i) {
        flag[i] = 0;
        father[i] = i;
    }
}
int main() {
    int n;
    cin>>n;
    string A,B;
    init();
    for(int i = 1;i <= n;++i) {
        cin>>A>>B;
        father[f(A)] = f(B);
        flag[f(B)] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= num;++i) {
        if(father[i] == i) ++ans;
    }
    printf("%d\n",ans);
    for(int i = 1;i <= num;++i) {
        if(flag[i]==0) {
            cout<<fin[i]<<" "<<fin[Find(i)]<<endl;
        }
    }
    return 0;
}
