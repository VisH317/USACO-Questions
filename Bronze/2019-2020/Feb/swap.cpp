#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n,k,a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;
    a--;b--;c--;d--;
    k = k%4;
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=i+1;
    for(int i=0;i<k;i++) {
        for(int j=0;j<ceil((a+b)/2)-a+1;j++) std::swap(arr[a+j], arr[b-j]);
        for(int j=0;j<ceil((c+d)/2)-c+1;j++) std::swap(arr[c+j], arr[d-j]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<'\n';
}