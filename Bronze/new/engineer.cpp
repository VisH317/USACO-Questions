#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101][101], b[101];

bool search(int index, vector<pair<int, int>> taken) {
    set<int> first, second;
    bool one=true,two=true;
    for(int i=0;i<m;i++) {
        if(a[i][index]==0) first.insert(b[i]);
        if(a[i][index]==1) second.insert(n[i]);
    }
    one = first.size()!=1 ? false : true;
    two = second.size()!=1 ? false : true;
    if(one&&two) return true;
    else {
        if(!one) {
            for(int i=0;i<n;i++) search()
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    int a[m][n], b[m], orig[m];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
            if(j==0) orig[i]==a[i][0];
        }
        cin>>b[i];
    }
    int zeros[n], ones[n];
    for(int i=0;i<n;i++) {
        
    }
}

int main() {
    int t;
    while(t--) solve();
}

// make a bool table of which bits are ambiguous for each side

// can be in any order, need to check for that
// difficult because need to check all orders and remove ones already determined in the program
// to prevent ambiguity when already decided
// look for determined bits, if so recursively check next bits until all taken
// 00 1
// 10 1
// 01 0
// 11 0
// complete search over all possible answers: 