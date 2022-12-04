#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int m = max(a, max(b, c));
    int n = min(a, min(b, c));
    int x = a!=m && a!=n ? a : b!=m && b!=n ? b : c;
    int maxDiff = max(abs(m-x), abs(n-x))-1;
    int minDiff =  log2(min(abs(a-b), min(abs(b-c), abs(a-c))));
    cout<<minDiff<<'\n'<<maxDiff<<endl;
}