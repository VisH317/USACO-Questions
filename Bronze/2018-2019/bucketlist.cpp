#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin>>n;
    int s[n], t[n], b[n];
    for(int i=0;i<n;i++) {
        cin>>s[i];
        cin>>t[i];
        cin>>b[i];
    }
    int maxb = 0;
    int i=1;
    int currentBuckets = 0;
    int sjc = 0;
    while(true) {
        for(int j=0;j<n;j++) {
            if(s[j]==i) {
                currentBuckets+=b[j];
                sjc++;
            }
            if(t[j]==i) currentBuckets-=b[j];
        }
        maxb = max(maxb, currentBuckets);
        if(sjc==n) break;
        i++;
    }
    cout<<maxb<<endl;
}