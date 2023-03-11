#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int sum = accumulate(a, a+n, 0);
    int ret;
    bool found = false;
    for(int i=0;i<sum;i++) {
        if(sum%i==0) {
            int accsum = 0;
            int total = 0;
            for(int j=0;j<n;j++) {
                accsum+=a[j];
                if(accsum>i) break;
                if(accsum==i) {
                    total++;
                    if(j==n-1) {
                        ret = total;
                        found = true;
                        break;
                    }
                    accsum=0;
                }
            }
        }
        if(found) break;
    }
    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}

// 1 2 3 1 1 1