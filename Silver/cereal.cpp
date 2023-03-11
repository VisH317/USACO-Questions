#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    pair<int, int> a[n];
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        a[i] = {x,y};
    }
    int ret[n];
    vector<int> cer(m, -1)
    for(int i=n-1;i>=0;i++) {
        if(cer[a[i].first]!=-1) {
            if(a[cer[a[i].first]]==)
        }
    }
}

// ok so loop through each and remove, go by timestep and implement
// go from end and give the first man his stuff, then go to next cow and give first if available
// if first not available give second, if second not available go to the occupying cow and move
// to second, if on second get rid of count