#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 100020 ;
int t,n,m,a,b;
char ope;

int enemy[MAXN];
int father[MAXN];
int Find(int x){
    if(x == father[x]) return father[x];
    return father[x] = Find(father[x]);
}
int Merge(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return 0;
    else father[a] = b;
    return 1;
}
void init(){
    for(int i = 1;i <= n;i++)
        father[i] = i;
}
int main()
{
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(enemy,0,sizeof(enemy));
        init();
        while(m--){
            scanf(" %c",&ope);
            scanf("%d%d",&a,&b);
            if(ope == 'D'){
                if(enemy[a]) Merge(enemy[a],b);
                if(enemy[b]) Merge(enemy[b],a);
                enemy[a] = b;
                enemy[b] = a;
            }
            else if(ope == 'A'){
                if(Find(a) == Find(b)) puts("In the same gang.");
                else if(Find(enemy[a]) == Find(b)) puts("In different gangs.");
                else puts("Not sure yet.");
            }
        }
    }
    return 0;
}
