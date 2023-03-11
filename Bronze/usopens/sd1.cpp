#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n;
    cin>>n;
    bool a[n];
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        a[i] = c=='1' ? true : false;
    };
    int prev = 0;
    vector<double> ds;
    int curMax = 0, prevMax = 0;
    int start = 0, end = 0;
    bool st = false;
    for(int i=0;i<n;i++) {
        if(!a[i]) prev++;
        if(a[i]) {
            if(i==0) {st=true;continue;}
            if(st==false) start = prev;
            ds.push_back(prev);
            prev=0;
        }
    }
    end = prev;
    sort(ds.begin(), ds.end());
    int twod = ((ds[ds.size()-1]+1)/3);
    int oned = (int)((ds[ds.size()-2]/2)-0.5)+1;
    int ret = min(max(twod, max(oned, max(start, end))), (int)(ds.size()==2 ? ds[1] : ds[0]+1));
    cout<<ret<<endl;
}