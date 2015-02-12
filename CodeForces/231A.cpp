/*************************************************************************
	> File Name: 231A_team.cpp
	> Author: jusonalien
	> Mail: jusonalien@mail.com 
	> Created Time: 2014年06月20日 星期五 15时14分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int n;
int t;
int k = 0;
int main()
{
    cin>>n;
    while(n--) {
        int h = 0;
        int o;
        for(int i = 1;i <= 3;i++) {
            cin>>o; h+= o ? 1 : 0;
        }
        k += h >= 2 ? 1 : 0;
    }
    cout<<k<<endl;
    return 0;
}
