////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: jusonalien
////Nickname: jusonalien
////Run ID: 
////Submit time: 2014-09-01 20:25:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4282
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:12760KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long
const int MAXN = 50000;
LL mat[MAXN + 1][32] = {0};

bool Bfind(int x,int z,int cnt){
    int l = x + 1,r = MAXN,mid;
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(mat[mid][z] == 0)
        {
            r = mid - 1;
            continue;
        }
        if(mat[mid][z] + x * mid * z < cnt) l = mid + 1;
        else if(mat[mid][z] + x * mid * z > cnt) r = mid - 1;
        else return true;
    }
    return false;
}
void init(){
    for(int i = 1;i <= MAXN;i++){
        mat[i][1] = i;
        for(int j = 2;j <= 31;j++){
            mat[i][j] = mat[i][j - 1]*i;
            if(mat[i][j]>2147483648LL) break;
        }
    }
}
int main()
{
    int k;
    init();
    while(scanf("%d",&k)&&k){
        LL sum = 0;
        int cnt;
        for(int x = 1;x <= MAXN;x++)
        for(int z = 2;z <= 31;z++){
            if(mat[x][z] == 0) break;
            cnt = k - mat[x][z];
            if(cnt - x * z <= 0) break;
            if(Bfind(x,z,cnt)) sum++;
        }
       printf("%I64d\n",sum);
    }
    return 0;
}