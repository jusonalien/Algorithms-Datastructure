#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a;
int MAX,MIN,length,ants;
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&length,&ants);
        MAX = MIN = 0;
        for(int i = 0;i < ants;i++) {
            scanf("%d",&a);
            MAX = max(MAX,max(a,length - a));
            MIN = max(MIN,min(a,length - a));
        }
        printf("%d %d\n",MIN,MAX);
    }
    return 0;
}
