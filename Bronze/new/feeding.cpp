#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k==0) {
        char a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        std::cout<<n<<endl;
        for(int i=0;i<n;i++) std::cout<<a[i];
        std::cout<<endl;
        return;
    }
    bool a[n];
    char ret[n];
    fill(ret,ret+n,'.');
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        if(c=='G') a[i]=true;
        else a[i]=false;
    }
    int count=0;
    int curg=-1*k-1,curh=-1*k-1;
    int startg=0,starth=0;
    for(int i=0;i<n;i++) {
        bool t = true;
        if(i==curg) {
            ret[i]='G';
            t=false;
            count++;
        }
        if(i==curh) {
            ret[i]='H';
            t=false;
            count++;
        }
        if(a[i]) {
            if(abs(i-curg)<=k) {
                if(t) ret[i]='.';
                continue;
            }
            startg=i;
            curg=min(i+k, n-1);
            if(i==n-1)count++;
        } else {
            if(abs(i-curh)<=k) {
                if(t) ret[i]='.';
                continue;
            }
            starth=i;
            curh=min(i+k, n-1);
            if(i==n-1)count++;
        }
    }
    if(curh==n-1) ret[n-1]='H';
    if(curg==n-1) ret[n-1]='G';
    if(curh==n-1&&curg==n-1) {
        if(a[n-1-k]) {
            ret[n-1]='H';
            ret[n-2]='G';
        } else {
            ret[n-1]='G';
            ret[n-2]='H';
        }
    }


    // check last
    std::cout<<count<<'\n';
    for(int i=0;i<n;i++) std::cout<<ret[i];
    std::cout<<endl;
}

int main() {
    int t;
    cin>>t;
    //vector<pair<int, char[]>> ret[t];
    while(t--) solve();
}

// check ending overrites
// check 0s