#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    vector<int> b;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        b.push_back(x);
    }
    sort(a,a+n, greater<int>());
    sort(b.begin(), b.end());
    long long ret = 1;
    for(int i=0;i<n;i++) {
        int idx=-1;
        for(int j=0;j<b.size();j++) {
            if(b[j]>=a[i]) {
                idx=j;
                break;
            }
        }
        if(idx==-1) {
            ret=0;
            break;
        }
        ret*=b.size()-idx;
        b.erase(b.begin()+idx);
    }
    cout<<ret<<endl;
}