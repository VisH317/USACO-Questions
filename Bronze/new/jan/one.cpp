#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool a[n];
    int e[n];
    int fg, fh, lg, lh;
    bool fgfound=false, fhfound=false;
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        if(c=='G') {
            if(!fgfound) {
                fgfound=true;
                fg=i;
            }
            lg=i;
            a[i]=true;
        }
        else {
            if(!fhfound) {
                fhfound=true;
                fh=i;
            }
            lh=i;
            a[i]=false;
        }
    }
    for(int i=0;i<n;i++) {
        int c;
        cin>>c;
        e[i] = c-1;
    }
    // check last - first is less than e, if no ones are then value 0
    int count = lg<=e[fg] && lh<=e[fh] ? 1 : 0;
    if(lg<=e[fg]) {
        for(int i=0;i<fg;i++) {
            if(!a[i] && fg<=e[i] && !(lh<=e[fh] && i==fh)) count++;
        }
    }
    if(lh<=e[fh]) {
        for(int i=0;i<fh;i++) {
            if(a[i] && fh<=e[i] && !(lg<=e[fg] && i==fg)) count++;
        }
    }
    cout<<count<<endl;
}

// 0 3 1 2