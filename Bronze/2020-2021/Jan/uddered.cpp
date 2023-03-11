#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    string word;
    getline(cin, a);
    getline(cin, word);
    int ret = 1;
    char prev = a.find(word[0]);
    for(int i=1;i<word.size();i++) {
        int idx = a.find(word[i]);
        if(idx<=prev) ret++;
        prev=idx;
    }
    cout<<ret<<endl;
}