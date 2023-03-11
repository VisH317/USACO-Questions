#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map<char, char> m, im;
    int count = 0;
    for(int i=0; i<s.length();i++) {
        if(m.find(s[i])!=m.end()) {
            if(t[i]!=m[s[i]]) {count=-1;break;}
            im[s[i]] = t[i];
            // im[t[i]] = s[i];
            continue;
        }
        else if(s[i]==t[i]) continue;
        else if(im.find(s[i])!=im.end()) {
            count++;
        }
        m[s[i]] = t[i];
        im[t[i]] = s[i];
        count++;
    }
    cout<<count<<endl;
}

int main() {
    int t;
    cin>>t;
    string d;
    getline(cin, d);
    while(t--) solve();
}
// BABA ABAB
// ABBC => EBBC => EAAC => BAAC => BAAB
// ABC => EBC => EFC => EFG 
// ABC => EBC => EBA => EFA => BFA => BCA
// ABCD => EBCD => EFCD => EFGD => EFGH
// AB => EB => EA => BA
//