#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n], b[n];
    map<int, int> avals;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int count=0;
    for(int i=0;i<n;i++) {
        avals[a[i]] = i;
        if(avals.find(b[i])!=avals.end()) {
            if(avals[b[i]]+count>i) count++;
        } else count++;
    }
    cout<<count<<endl;
}

// 7
// 1 2 3 4 5 6 7
// 7 6 4 5 1 3 2
// 7 6 1 2 3 4 5
// 7 6 4 5 1 3 2


// 7 6 4 1 2 3 5
// 7 6 4 5 1 2 3
// 7 6 4 5 1 3 2

// have an offset counter, if on right then add 1, if on left add offset and check still left
// if move to right then add 1
// theres simpler: iterate through the list so you have the left side
// make a hashmap of values to indexes: if not in there then on right, if in use the index pog