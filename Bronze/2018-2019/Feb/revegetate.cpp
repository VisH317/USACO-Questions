#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a[n];
    int ret[n];
    ret[0]=1;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        a[max(x-1,y-1)].push_back(min(x-1,y-1));
    }
    for(int i=1;i<n;i++) {
        set<int> taken;
        for(int x:a[i]) taken.insert(ret[x]);
        for(int y=1;y<=4;y++) {
            if(find(taken.begin(), taken.end(), y)!=taken.end()) ret[i]=y+1;
            else {
                ret[i]=y;
                break;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ret[i];
    cout<<endl;
}

