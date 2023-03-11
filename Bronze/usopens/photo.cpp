#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool a[n];
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        if(c=='G') a[i] = true;
        else a[i] = false;
    }
    for(int i=0;i<n;i++) {
        if(i%2==0 && a[i])
    }
}