#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)c[i]=a[i]-b[i];
    bool curSign = c[0]>0 ? true : false;
    int count = 0;
    count+=abs(c[0]);
    for(int i=1;i<n;i++) {
        if(c[i]==0) continue;
        int sign = c[i]>0 ? true : false;
        if(sign!=curSign) {
            count+=abs(c[i]);
            continue;
        }
        count+=c[i]-c[i-1]<0 ? 0 : c[i]-c[i-1];
    }
    cout<<count<<endl;
}

// 0 3 2 1 3
// 3 2 1 2
// if sign change: reset max carry and try again
// if decrease, ignore
// if increase, add by current - previous
// 1 2 3 2
// 2 1 2 3
