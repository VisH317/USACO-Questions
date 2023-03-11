#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n,m,c;
    cin>>n>>m>>c;
    priority_queue<int> a;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.push(x);
    }
    vector<int> res;
    while(!a.empty()) {
        res.insert(res.begin(), a.top());
        a.pop();
    }

    int end = n-1;
    int start = 2*(int)(n/c)-1;
    int count = n-1;
    int maxtime = 0;
    for(int i=1;i<=m;i++) {
        int end = i*c-1>n-1 ? n-1 : i*c-1;
        int start = (i-1)*c;
        int time = res[end] - res[start];
        maxtime = max(maxtime, time);
    }

    cout<<maxtime<<endl;
}
// binary search over all possible times
//