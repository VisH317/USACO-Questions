#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin>>n;
    vector<string> a[n];
    for(int i=0;i<n;i++) {
        string name;
        cin>>name;
        int x;
        cin>>x;
        vector<string> b;
        for(int j=0;j<x;j++) {
            string desc;
            cin>>desc;
            b.push_back(desc);
            // if(counts.find(desc)==counts.end()) counts[desc]=1;
            // else counts[desc]++;
        }
        a[i] = b;
    }
    int maxCount = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            int count = 0;
            for(string s : a[i]) {
                if(find(a[j].begin(), a[j].end(), s) != a[j].end()) {
                    count++;
                }
            }
            maxCount = max(maxCount, count);
        }
    }
    cout<<maxCount+1<<endl;
}