/*********************************
Author: jusonalien
Email : jusonalien@qq.com
school: South China Normal University
origin: POJ 2503_Trie Tree
*********************************/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <queue>
using namespace std;
const int maxnode = 611111;
const int sigma_size = 28;
struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    void init(){
        sz = 1;memset(ch[0],0,sizeof(ch[0]));
    }
    int idx(char c){return c - 'a';}
    void insert(char* s,int v){
        int u = 0,n = strlen(s);
        for(int i = 0;i < n;i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int find(const char* s){
        int u = 0, n = strlen(s);
        for(int i = 0;i < n;i++){
            int c = idx(s[i]);
            if(ch[u][c] == 0) return 0;
            u = ch[u][c];
        }
        return val[u];
    }
} T;
char s[200];
char mp[101000][20];
int main(){
    T.init();
    int n = 0;
    while(1){
        gets(s);
        if(!strlen(s)) break;
        int l = 0;
        char *start = strchr(s,' ');
        int End = start - s ;
        s[End] = '\0';
        T.insert(start+1,++n);
        strcpy(mp[n],s);
    }
    while(~scanf("%s",s)){
        int k = T.find(s);
        puts(k?mp[k]:"eh");
    }
    return 0;
}
