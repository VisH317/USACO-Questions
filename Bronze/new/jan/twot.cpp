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
    int cost = 0;
    vector<int> used;
    for(int i=1;i<101;i++) {
        if(a[i]<=0) continue;
        int total;
        for(int j=0;j<c.size();j++) {
            
        }
    }
}

// go by stall number throughout, determine which ones are required
// check if remove the previous ones when adding a new one