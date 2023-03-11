#include <bits/stdc++.h>
using namespace std;

int MAXN = 10001;

int main() {
    int n;
    cin>>n;
    int a[n], b[n], diff[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) diff[i] = a[i]-b[i];
    int cnt = 0;
    int streak = 1;
    int m = MAXN;
    int prev=0;
    for(int i=0;i<n;i++) {
        int sign = diff[i]==0 ? 0 : diff[i]>0 ? 1 : -1;
        cnt+=abs(diff[i]);
        if(sign!=prev) {
            cnt-=(streak-1)*m;
            streak = 1;
            m = abs(diff[i]);
        } else if(sign==prev) {
            streak++;
            m = min(m, abs(diff[i]));
            prev=sign;
        }
        prev=sign;
    }
    cnt-=(streak-1)*m;
    cout<<cnt<<endl;
}