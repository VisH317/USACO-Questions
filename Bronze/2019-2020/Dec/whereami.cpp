#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int count = 1;
    for(int i=1;i<=n;i++) {
        set<string> used;
        bool t = true;
        for(int j=0;j<=n-i+1;j++) {
            string current = a.substr(j,i);
            if(find(used.begin(), used.end(), current) != used.end()) {
                t = false;
                break;
            }
            used.insert(current);
        }
        if(t) {
            count = i;
            break;
        }
    }
    cout<<count<<endl;
}