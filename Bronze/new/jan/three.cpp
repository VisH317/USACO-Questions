#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

void solve() {
    string s;
    getline(cin, s);
    int count = s.length()-3;
    if(count<0) cout<<-1<<endl;
    else {
        int value = 10001;
        for(int i=0;i<s.length()-2;i++) {
            string x = s.substr(i,3);
            if(s[i+1]=='O') value = min(value, m[x]);
        }
        if(value==10001) cout<<-1<<endl;
        else {
            int ret = count+value;
            cout<<ret<<endl;
        }
    }
}

int main() {
    m["MOO"] = 0;
    m["OOM"] = 2;
    m["OOO"] = 1;
    m["MOM"] = 1;
    int n;
    cin>>n;
    string dummy;
    getline(cin, dummy);
    while(n--) solve();
}