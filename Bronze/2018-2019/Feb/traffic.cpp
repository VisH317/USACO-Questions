#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n;
    cin>>n;
    string s[n];
    pair<int, int> a[n];
    for(int i=0;i<n;i++) {
        cin>>s[i];
        int x,y;
        cin>>x>>y;
        a[i] = make_pair(x,y);
    }
    // find end mile
    int x=0, y=1001;
    for(int i=n-1;i>=0;i--) {
        if(i==n-1&&(s[i]=="on"||s[i]=="off")) continue;
        if(s[i]=="none") {
            x = max(x, a[i].first);
            y = min(y, a[i].second);
        }
        if(s[i]=="off") {
            x+=a[i].first;
            y+=a[i].second;
        }
        if(s[i]=="on") {
            x-=a[i].second;
            y-=a[i].first;
        }
    }
    cout<<x<<' '<<y<<endl;
    x=0, y=1001;
    for(int i=0;i<n;i++) {
        if(i==0 && (s[i]=="on"||s[i]=="off")) continue;
        if(s[i]=="none") {
            x = max(x, a[i].first);
            y = min(y, a[i].second);
        }
        if(s[i]=="on") {
            x+=a[i].first;
            y+=a[i].second;
        }
        if(s[i]=="off") {
            x-=a[i].second;
            y-=a[i].first;
        }
    }
    cout<<x<<' '<<y<<endl;
}