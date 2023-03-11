#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> b, r, l;
    for(int i=0;i<10;i++) {
        for(int j=0;j<1=;j++) {
            char c;
            cin>>c;
            if(c=='B') b = {i, j};
            if(c=='R') r = {i,j};
            if(c=='L') l = {i,j};
        }
    }
    if(b.first==r.first && r.first==l.first) {
        int ret = abs(b.first-l.first)+2;
        cout<<ret<<endl;  
    } else if(b.second==r.second && r.second==l.second) {
        int ret = abs(b.second-l.second)+2;
        cout<<ret<<endl;
    } else {
        int ret = abs(b.first-l.first)+abs(b.second-l.second)-1;
        cout<<ret<<endl;
    }
}
// flying, spots telepathic flying
// spots fire-breathing telepathic flying, telepathic flying monkey, fire-breathing
// can organize it into a tree but there is probably a simpler solution