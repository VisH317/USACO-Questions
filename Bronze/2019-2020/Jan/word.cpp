#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    int count = 0;
    string a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<a[0];
    count+=a[0].length();
    for(int i=1;i<n;i++) {
        count+=a[i].length();
        if(count>k) {
            cout<<'\n'<<a[i];
            count=a[i].length();
        } else cout<<' '<<a[i];
    }
    cout<<endl;
}