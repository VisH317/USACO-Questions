#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int count = 0;
    bool same = false, neg = false;
    while(!same || !neg) {
        int min = *min_element(a, a+n);
        bool curSame = false;
        for(int i=0;i<n-1;i++) {
            if(a[i]<min) {curSame = true;continue;}
            else if(a[i]==min) continue;
            a[i+1] -= a[i] - min;
            a[i] = min;
            count+= a[i]-min;
            curSame = true;
            if(a[i]<0||a[i+1]||0) neg = true;
        }
    }
    if(neg) cout<<-1<<endl;
    else cout<<count<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}

// 8 10 5
// 5 7 5
// 5 5 3
// 3 3 3
// next check: all same, good