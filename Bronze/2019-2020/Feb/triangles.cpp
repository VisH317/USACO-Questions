#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    pair<int, int> a[n];
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[i] = make_pair(x, y);
    }
}