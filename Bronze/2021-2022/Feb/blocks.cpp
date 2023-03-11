#include <bits/stdc++.h>
using namespace std;

set<char> blocks[4];
vector<int> which[4];

void solve() {
    string s;
    getline(cin, s);
    int works = true;
    for(int i=0;i<s.length();i++) {
        // check which possible blocks, check which being used, if multiple used add and make the pair one time use
        vector<int> posBlocks;
        for(int j=0;j<4;j++) {
            if(blocks[j].find(s[i])!=blocks[j].end()) posBlocks.push_back(j);
        }
        for(int j=0;j<i;j++) {
            for(int k=0;k<posBlocks.size();k++) {
                if((find(which[j].begin(), which[j].end(), posBlocks[k])!=which[j].end())) {
                    if(which[j].size()==1) posBlocks.erase(posBlocks.begin()+k);
                    else which[j].erase(find(which[j].begin(), which[j].end(), posBlocks[k]));
                }
            }
        }
        if(posBlocks.size()==0) {
            works=false;
            break;
        }
        which[i] = posBlocks;
    }
    if(works) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<4;i++) {
        for(int j=0;j<6;j++) {
            char c;
            cin>>c;
            blocks[i].insert(c);
        }
    }
    while(n--) solve();
}

// add all blocks that are not previously used to a letter
// if previously used with multiple then add if has the letter