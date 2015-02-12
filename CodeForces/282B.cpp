/*************************************************************************
	> File Name: cf_282A_Bit++.cpp
	> Author: jusonalien
	> Mail: jusonalien@mail.com 
	> Created Time: 2014年06月20日 星期五 14时52分45秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string plus_ = "X++";
string _plus = "++X";
string reduce_ = "X--";
string _reduce = "--X";
string operation ;
int n ;
int x = 0;
int main()
{
    cin>>n;
    while(n--) {
        cin>>operation;
        if(operation == plus_ ) x++;
        if(operation == _plus ) ++x;
        if(operation == reduce_) x--;
        if(operation == _reduce ) --x;
    }
    cout<<x<<endl;
    return 0;
}
