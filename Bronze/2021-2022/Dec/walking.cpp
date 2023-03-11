#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    bool a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            char c;
            cin>>c;
            a[i][j] = c=='.' ? false : true;
        }
    }

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}