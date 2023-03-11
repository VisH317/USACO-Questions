#include <bits/stdc++.h>
using namespace std;

string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<bool> completed(8, false);
vector<int> rel[8];

bool check_cow(int i) {
    if(rel[i].size()>=2) return false;
    if(completed[i]) return false;
    completed[i] = true;
    if(rel[i].size()==1) completed[rel[i][0]] = true;
    return true;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string cow1, cow2, ext;
        cin>>cow1>>ext>>ext>>ext>>ext>>cow2;
        int idx1 = distance(cows, find(cows, cows+8, cow1));
        int idx2 = distance(cows, find(cows, cows+8, cow2));
        rel[idx1].push_back(idx2);
        rel[idx2].push_back(idx1);
    }

    for(int i=0;i<8;i++) {
        if(check_cow(i)) {
            cout<<cows[i]<<endl;
            if(rel[i].size()==1) cout<<cows[rel[i][0]]<<endl;
        }
    }
}