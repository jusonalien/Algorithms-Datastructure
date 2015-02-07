#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int Partition(int a[],int low,int high) {
    while(low < high) {
        a[0] = a[low];
        while(low < high&&a[0] <= a[high])
            --high;
        a[low] = a[high];
        while(low < high&&a[low] <= a[0])
            ++low;
        a[high] = a[low];
    }
    a[low] = a[0];
    return low;
}
void QucikSort(int a[],int low,int high) {
    if(low < high) {
    int pos = Partition(a,low,high);
    QucikSort(a,low,pos-1);
    QucikSort(a,pos+1,high);
    }
}
int main() {
    int a[1111];
    int n;
    while(cin>>n) {
        for(int i = 1;i <= n;++i) cin>>a[i];
        QucikSort(a,1,n);
        for(int i = 1;i <= n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
