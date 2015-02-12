/*
当k为偶数时，s(k)=(1+A^(k/2))*(A+A^2+…+A^(k/2))
• 当k为奇数时，s(k)=A+(A+A^(k/2+1))*(A+A^2+…+A^(k/2))加以递归求解，get到新技能 orz
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int MAX = 32;
struct Matrix{
    int v[MAX][MAX];
};
Matrix E;//定义单位矩阵 E
int n,k,M;
Matrix add(Matrix a,Matrix b){//矩阵加法运算
    Matrix c;
    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++){
        c.v[i][j] = (a.v[i][j] + b.v[i][j]) % M;
    }
    return c;
}
Matrix mul(Matrix a,Matrix b){//矩阵乘法运算
    Matrix c;
    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++){
        c.v[i][j] = 0;
        for(int k = 1;k <= n;k++)
        c.v[i][j] = (a.v[i][k] * b.v[k][j] + c.v[i][j]) % M;
    }
    return c;
}
Matrix pow(Matrix a,int k){//矩阵幂运算
    if(k == 0){
        memset(a.v,0,sizeof(a.v));
        for(int i = 1;i <= n;i++)
            a.v[i][i] = 1;
        return a;
    }else if(k == 1) return a;
    Matrix c = pow(a,k / 2);
     if(k & 1){
        return mul(a,mul(c,c));
    }else
        return mul(c,c);
}
Matrix sum(Matrix a,int k){ //连续升幂求和
    if(k == 1)return a;
    Matrix b = pow(a,(k + 1) / 2);
    Matrix c = sum(a,k / 2);
    if(k % 2){
        return add(a,mul(add(a,b),c));
    }else
        return mul(add(E,b),c);
}
void initE(){ //初始化单位矩阵E
    memset(E.v,0,sizeof(E.v));
    for(int i = 1;i <= n;i++) E.v[i][i] = 1;
}
void print(Matrix a){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
        printf("%d ",a.v[i][j]);
        puts("");
    }
}
Matrix get(){
    Matrix a;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)scanf(" %d",&a.v[i][j]);
    return a;
}
int main()
{

    while(~scanf("%d%d%d",&n,&k,&M)){
        initE();
        Matrix a = get();
        Matrix b = sum(a,k);
        print(b);
        }
    return 0;
}
