#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int a[3], b[3];
    for(int i=0;i<3;i++) {
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=0;i<100;i++) {
        int prevb = b[i%3==2 ? 0 : i%3+1];
        b[i%3==2 ? 0 : i%3+1] = min(a[i%3==2 ? 0 : i%3+1], b[i%3]+b[i%3==2 ? 0 : i%3+1]);
        b[i%3] -= b[i%3==2 ? 0 : i%3+1]-prevb;
    }
    cout<<b[0]<<'\n'<<b[1]<<'\n'<<b[2]<<'\n';
}