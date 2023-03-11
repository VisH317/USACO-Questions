#include <bits/stdc++.h>
using namespace std;

struct Cond {
    int a;
    int b;
    int p;
    int m;
    Cond(int a, int b, int p, int m) : a(a), b(b), p(p), m(m) {};
    bool operator<(const Cond& c) {return m < c.m;}
};


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(101, 0);
    for(int i=0;i<n;i++) {
        int s,t,c;
        cin>>s>>t>>c;
        for(int i=s;i<=t;i++) a[i]+=c;
    }
    vector<Cond> c;
    for(int i=0;i<m;i++) {
        int a,b,p,m;
        cin>>a>>b>>p>>m;
        c.push_back(Cond(a,b,p,m));
    }
    sort(begin(c), end(c));
    for(int i=0;i<m;i++) {
        // iterate for each length
        vector<int> conds;
        for(int j=0;j<=i+1)
    }
}

// add air conditioners one by one by cost until all satisfied
// always within time constraints due to puny numbers
// recursive search, search by length, then by numbers