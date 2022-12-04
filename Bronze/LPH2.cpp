#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int r=0;
    for(int i=0;i<n-2;i++) {
        int g=0,h=0;
        int inc=3;
        if(a[i]=='G') g++;
        else h++;
        if(a[i+1]=='G') g++;
        else h++;
        if(a[i+2]=='G') g++;
        else h++;
        if(g>0&&h>0&&(g<2||h<2)) r+=1;
        while((g<2 || h<2)) {
            if(a[i+inc]=='G') g++;
            else h++;
            if((g<2 || h<2)&&g>0&&h>0) r++;
            inc++;
        }
    }

    cout<<r<<endl;
}

// need to think of every possible test case