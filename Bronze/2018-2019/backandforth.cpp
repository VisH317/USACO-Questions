#include <bits/stdc++.h>
using namespace std;

set<int> possible;

void getPossible(int day, int a_tank, int b_tank, vector<int> a_buckets, vector<int> b_buckets) {
    
    if(day==4) {
        possible.insert(a_tank);
        return;
    }

    for(int i=0;i<a_buckets.size();i++) {
        int t = a_buckets[i];
        vector<int> new_a = a_buckets;
        new_a.erase(begin(new_a)+i);
        vector<int> new_b = b_buckets;
        new_b.push_back(a_buckets[i]);
        getPossible(day+1, b_tank+t, a_tank-t, new_b, new_a);
    }
}


int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> a(10);
    vector<int> b(10);
    int a_tank=1000, b_tank=1000;
    for(int& i:a) cin>>i;
    for(int& i:b) cin>>i;
    getPossible(0, 1000, 1000, a, b);
    cout<<possible.size()<<endl;
}