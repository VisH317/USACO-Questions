#include <bits/stdc++.h>
using namespace std;

int main() {
    char a[9], b[9];
    map<char, int> abc, iabc;
    for(int i=0;i<9;i++) {
        cin>>a[i];
        if(iabc.find(a[i])==iabc.end()) iabc[a[i]]=1;
        else iabc[a[i]]++;
    }
    for(int i=0;i<9;i++) cin>>b[i];
    int green=0,yellow=0;
    for(int i=0;i<9;i++) {
        if(abc.find(b[i])==abc.end()) abc[b[i]]=1;
        else abc[b[i]]++;
        if(a[i]==b[i]) {
            green++;
            continue;
        }
        if(abc[b[i]]<=iabc[b[i]]) yellow++;
    }
    cout<<green<<endl<<yellow<<endl;
}