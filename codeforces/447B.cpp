#include<iostream>
#include<string.h>
using namespace std;
int w[28];
char s[1010];
int k;
int sum = 0;
int main()
{
    //cout<<'z' - 'a' + 1<<endl;
    cin>>s>>k;
    int MAX = 0;
    for(int i = 1;i <= 26;i++) {
        cin>>w[i];
        MAX = max(MAX,w[i]);
    }
    for(int i = 0;i < strlen(s);i++)
        sum += (i + 1) * w[s[i] - 'a' + 1];
       // cout<<sum<<endl;
    for(int i = strlen(s) +1;i <= strlen(s) + k;i++)
        sum += i * MAX;
    cout<<sum<<endl;
    return 0;
}
