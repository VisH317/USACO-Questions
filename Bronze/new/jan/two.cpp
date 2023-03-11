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

int search(int length, vector<Cond>& c, vector<int> a, vector<int> possible, int cost) {
    if(length==0) {
        bool check = true;
        for(int i=0;i<a.size();i++) {
            if(a[i]>0) {check=false;break;}
        }
        if(check) {
            return cost;
        }
        else return -1;
    }
    int mi = 1000001;
    for(int i=0;i<possible.size()-length+1;i++) {
        vector<int> pc = possible;
        for(int j=0;j<=i;j++) pc.erase(pc.begin());
        vector<int> ac = a;
        for(int j=c[possible[i]].a;j<=c[possible[i]].b;j++) {
            ac[j]-=c[possible[i]].p;
        }
        int val = search(length-1, c, ac, pc, cost+c[possible[i]].m);
        if(val==-1) continue;
        mi = min(mi, val);
    }
    return mi;
}


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
    int mi = 10000001;
    for(int i=0;i<m;i++) {
         vector<int> possible;
         for(int i=0;i<m;i++) possible.push_back(i);
         int val = search(i+1, c, a, possible, 0);
        //  if(val==-1) continue;
         mi = min(mi, val);
    }
    if(mi==10000001) mi=-1;
    cout<<mi<<endl;
}

// add air conditioners one by one by cost until all satisfied
// always within time constraints due to puny numbers
// recursive search, search by length, then by numbers