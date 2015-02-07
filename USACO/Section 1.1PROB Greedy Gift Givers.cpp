/*
ID: jusonal1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
ofstream fout("gift1.out");
ifstream fin("gift1.in");
map<string,int> hehe;
int NP;
string name[15];
int    mon[15];
void print(){
    for(int i = 1;i <= NP;++i){
        fout<<name[i]<<" "<<mon[i]<<endl;
    }
}
int find_(string a){
    for(int i = 1;i <= NP;++i){
        if(a == name[i]) return i;
    }
}
int main ()
{

  string giving,gived;
  int giving_num,giving_money;
  fin>>NP;
  for(int i = 1;i <= NP;++i) {fin>>name[i];mon[i] = 0;}

  for(int i = 1;i <= NP;++i){
    fin>>giving>>giving_money>>giving_num;
    if(giving_money==0&&giving_num==0){
        continue;
    }

    //mon[find_(giving)] += giving_money % giving_num;
    mon[find_(giving)] -= giving_money - giving_money % giving_num;
    int money = giving_money / giving_num;

    for(int i = 1;i <= giving_num;++i){
        fin>>gived; mon[find_(gived)] += money;
    }
  }
    print();
  return 0;
}
