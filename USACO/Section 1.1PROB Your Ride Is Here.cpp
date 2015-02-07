/*
ID: jusonal1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int n(char a){
    return a - 'A' + 1;
}
int num(string a){
    int ans = 1;
    for(int i = 0;a[i] != '\0';++i)
        ans = ans*n(a[i])%47;
    return ans;
}
int main ()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string a,b;
  fin>>a>>b;
  //cin>>a>>b;
  if(num(a) == num(b)) fout<<"GO"<<endl;
  else fout<<"STAY"<<endl;
  return 0;
}
