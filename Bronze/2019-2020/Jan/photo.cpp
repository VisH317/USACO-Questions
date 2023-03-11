#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n;
    cin>>n;
    int a[n-1];
    int counts[n];
    for(int i=0;i<n-1;i++) cin>>a[i];
    int init = 1;
    int ret[n];
    while(true) {
        fill(ret, ret+n,0);
        fill(counts, counts+n, 0);
        counts[init-1]++;
        ret[0] = init;
        bool t = true;
        for(int i=1;i<n;i++) {
            ret[i] = a[i-1]-ret[i-1];
            if(ret[i]<=0 || ret[i]>n) {
                init++;
                t = false;
                break;
            }
            counts[ret[i]-1]++;
            if(counts[ret[i]-1]>1) {
                init++;
                t = false;
                break;
            }
        }
        if(!t) continue;
        break;
    }
    for(int i=0;i<n-1;i++) cout<<ret[i]<<' ';
    cout<<ret[n-1]<<endl;
}