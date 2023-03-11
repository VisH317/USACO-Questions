#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ret = n;
    for(int l=2;l<=n;l++) {
        for(int i=0;i<n-l+1;i++) {
            int sum = 0;
            for(int j=i;j<i+l;j++) sum+=a[j];
            bool t = false;
            for(int k=i;k<i+l;k++) {
                if(a[k]*l==sum) t= true;
            }
            if(t) ret++;
        }
    }
    cout<<ret<<endl;
}