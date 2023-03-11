#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int n;
    cin>>n;
    pair<int, int> a[n];
    for(int i=0;i<n;i++) {
        int x,s;
        cin>>x>>s;
        a[i] = {x,s};
    }
    sort(a, a+n, [](auto &left, auto &right) {return left.first < right.first;});
    int r = 100001;
    int pr;
    bool prfound = false;
    if(a[0].second==1) {prfound=true;pr=0;}
    for(int i=1;i<n;i++) {
        if(!prfound && a[i].second==1) {prfound=true;pr=i;}
        if(a[i].second!=a[i-1].second) r = min(r, a[i].first-a[i-1].first);
    } 
    int count = prfound ? 1 : 0;
    if(!prfound) pr=n;
    for(int i=pr+1;i<n;i++) {
        if(a[i].second==1) {
            if(a[i].first-a[pr].first>=r) count++;
            pr=i;
        }
    }
    cout<<count<<endl;
}

// two passes, first pass find the maximum r by checking changes and updating with max
// second pass, find the minimum cows by choosing the first cow and using that to see future infected
// for finding minimum cows: must check first and lass
// nvm stop overcomplicating LMAOOOOO