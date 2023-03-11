#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k,n;
    cin>>k>>n;
    int a[k][n];
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            bool t = true;
            for(int x=0;x<k;x++) {
                if(distance(a[x], find(a[x], a[x]+n,j+1))>distance(a[x], find(a[x], a[x]+n,i+1))) {
                    t = false;
                }
            }
            if(t) count++;
        }
    }
    cout<<count<<endl;
}