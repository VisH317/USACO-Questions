#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin>>n;
    pair<int, int> a[n];
    int g[n];
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[i] = make_pair(x, y);
        cin>>g[i];
    }
    int maxCount = 0;
    for(int i=1;i<=3;i++) {
        int ip = i;
        int count=0;
        for(int j=0;j<n;j++) {
            if(a[j].first==ip) ip=a[j].second;
            else if(a[j].second==ip) ip=a[j].first;
            if(ip==g[j]) count++;
        }
        maxCount = max(maxCount, count);
    }
    cout<<maxCount<<endl;
}