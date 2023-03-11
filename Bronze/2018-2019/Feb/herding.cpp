#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int a,b,c;
    cin>>a>>b>>c;
    int m = max(a, max(b, c));
    int n = min(a, min(b, c));
    int x = a!=m && a!=n ? a : b!=m && b!=n ? b : c;
    int maxDiff = max(abs(m-x), abs(n-x))-1;
    int minDiff;
    if(m-n==2) minDiff=0;
    else if(abs(m-x)==2||abs(x-n)==2) minDiff=1;
    else minDiff=2;
    cout<<minDiff<<'\n'<<maxDiff<<endl;
}