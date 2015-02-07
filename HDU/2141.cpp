////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:27:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 550;
int l,n,m,s,k,amb,cas = 0;
int L[MAXN],N[MAXN],M[MAXN];
int a[MAXN*MAXN];
int main()
{
        while(~scanf("%d%d%d",&l,&n,&m)){
        for(int i = 0;i < l;i++) scanf("%d",&L[i]);
        for(int i = 0;i < n;i++) scanf("%d",&N[i]);
        for(int i = 0;i < m;i++) scanf("%d",&M[i]);
        int cou = 0;
        for(int i = 0;i < l;i++)
        for(int j = 0;j < n;j++){
            a[cou++] = L[i] + N[j];
        }
        sort(a,a + cou);
        printf("Case %d:\n",++cas);
        scanf("%d",&s);
            while(s--){
            scanf("%d",&amb);
            for(int i = 0;i < m;i++){
                k = amb - M[i];
                if(binary_search(a,a+cou,k)){
                    puts("YES");goto flag;
                }
            }
            puts("NO");
            flag: continue;
      }
    }
    return 0;
}