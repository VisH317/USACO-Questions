#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int count=0;
    int g1=0,g2=0,h1=0,h2=0;
    bool g=false,h=false;
    int it = 0;
    int sumg=0;
    for(int i=0;i<3;i++) if(a[i]=='G')sumg++;
    if(sumg==2||sumg==1) count++;
    for(int i=3;i<n;i++) {
        if(a[i-3]=='G') {
            g2=g1;
            g1=i-3;
        } else {
            h2=h1;
            h1=i-3;
        }
        int cur=0;
        int sg=0;
        for(int j=i-2;j<i+1;j++) if(a[j]=='G')sg++;
        if(sg==3) cur=h1-h2;
        if(sg==0) cur=g1-g2;
        if(sg==2) cur=i-2-h1;
        if(sg==1) cur=i-2-g1;
        count+=cur;
    }
    cout<<count<<endl;
}

//GGGHHGHGHGGGG
//HHGGGGHH
//HHG 1
//HHGG 1
//HHGGG 1
//HHGGGG 1
//HHGGGGHH