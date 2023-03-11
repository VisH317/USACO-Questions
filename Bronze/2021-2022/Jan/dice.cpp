#include <bits/stdc++.h>
using namespace std;

bool isWin(int (&a)[4], int (&b)[4]) {
    int one=0,two=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(a[i]>b[j]) one++;
            else if(a[i]<b[j]) two++;
        }
    }
    return one>two;
}

void solve() {
    int a[4], b[4];
    bool ret = false;
    for(int i=0;i<4;i++) cin>>a[i];
    for(int i=0;i<4;i++) cin>>b[i];
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            for(int k=0;k<10;k++) {
                for(int l=0;l<10;l++) {
                    int c[] = {i,j,k,l};
                    if((isWin(a,b)&&isWin(b,c)&&isWin(c,a)) || (isWin(b,a)&&isWin(c,b)&&isWin(a,c))) {
                        ret = true;
                        break;
                    }
                }
                if(ret) break;
            }
            if(ret) break;
        }
        if(ret) break;
    }
    string r = ret ? "yes" : "no";
    cout<<r<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}

// 5.5, 5.25, 5.5