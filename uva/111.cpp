#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 30;
int ID[maxn];
int b[maxn];
int ans1,ans2;
int a[maxn];
int c[maxn];
int n;
int opt[maxn];
int solve(){
    int MAX = 0;
    a[0] = -100;
    memset(opt,0,sizeof(opt));
    for(int i = 1;i <= n;++i)
    for(int j = 0;j <= i-1;++j){
        if(a[j] <= a[i])
            opt[i] = max(opt[i],opt[j] + 1);
    }
    for(int i = 1;i <= n;++i){
        MAX = max(MAX,opt[i]);
    }
    return MAX;
}
void print(){
    for(int i = 1;i <= n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
int getid(int index){
    for(int i = 1;i <= n;++i)
        if(ID[i] == index)
        return i;
}
int main(){
    //freopen("in.txt","r",stdin);
    int fuck;
    while(~scanf("%d",&n)){
        for(int i = 1;i <= n;++i){
            scanf("%d",&fuck);
            ID[fuck] = i;
        }
        while(1){
            ans1 = 0;
            for(int i = 1;i <= n;++i){
                if(scanf("%d",&fuck)==EOF) goto holly_shit;
                a[fuck] = getid(i);
            }
            printf("%d\n",solve());
            memset(a,0,sizeof(a));
        }
        holly_shit: continue;
    }
    return 0;
}
