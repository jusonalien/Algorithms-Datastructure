/*************************************************************************
	> File Name: 3253.cpp
	> Author: jusonalien
	> Mail: jusonalien@qq.com
	> Created Time: 2015年02月11日 星期三 23时34分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
        
    priority_queue<int,vector<int>,greater<int> > q;
    int n;
    while(~scanf("%d",&n)) {
        while(!q.empty()) q.pop();
        long long  ans = 0;
        int ele;
        while(n--) {
            scanf("%d",&ele);
            q.push(ele);
        }
        while(!q.empty()) {
            int d = q.top();
            ans += q.top();
            q.pop();
            if(q.empty()) break;
            d += q.top();
            ans += q.top();
            q.pop();
            if(q.empty()) break;
            q.push(d);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
