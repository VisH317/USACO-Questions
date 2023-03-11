#include <bits/stdc++.h>
using namespace std;

string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<string> answer, beside_a, beside_b;

int where(string s) {
    for(int i=0;i<answer.size();i++) {
        if(answer[i]==s) return i;
    }
    return 999;
}

bool canGoFirst(string s, int n) {
    int adj=0, x=answer.size();
    if(where(s)!=999) return false;
    for(int i=0;i<n;i++) {
        if(beside_a[i]==s && where(beside_b[i])==999) adj++;
        if(beside_b[i]==c && where(beside_a[i])==999) adj++;
    }
    if(adj==2) return false;
    if(n>0) {
        string last_cow = answer[x-1];
        for(int i=0;i<n;i++) {
            if (beside_a[i]==last_cow && where(beside_b[i])==999 && beside_b[i]!=s) return false;
            if (beside_b[i]==last_cow && where(beside_a[i])==999 && beside_a[i]!=s) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    pair<string, string> inst[n];
    for(int i=0;i<n;i++) {
        string s,t,d;
        cin>>s;
        cin>>d;
        cin>>d;
        cin>>d;
        cin>>d;
        cin>>t;
        beside_a.push_back(s);
        beside_b.push_back(t);
    }
    for(int i=0;i<8;i++) {
        int next_cow = 0;
        while(!can_go_first(cows[next_cow])) next_cow++;
        answer.push_back(cows[next_cow]);
        cout<<cows[next_cow]<<'\n';
    }
}

//belinda and buttercup, blue and belinda, blue and sue

 // int sIndex = distance(cows, find(cows, cows+8,s));
        // int tIndex = distance(cows, find(cows, cows+8,t));
        // if(sIndex<tIndex) {
        //     if(rel.find(s)!=rel.end()) {
        //         if(rel[s].second.size()!=0) {
        //             int fIndex = distance(cows, find(cows, cows+8,rel[s].second));
        //             int cIndex = distance(cows, find(cows, cows+8,s));
        //             if(fIndex<cIndex) {
        //                 rel[s].first=rel[s].second;
        //                 rel[s].second=t;
        //             } else {
        //                 rel[s].first=t;
        //             }
        //         } else rel[s].second = t;
        //     }
        // } else if(sIndex>tIndex) {
        //     if(rel.find(t)!=rel.end()) {
        //         if(rel[t].second.size()!=0) {
        //             int fIndex = distance(cows, find(cows, cows+8,rel[s].second));
        //             int cIndex = distance(cows, find(cows, cows+8,s));
        //             if(fIndex<cIndex) {
        //                 rel[s].first=rel[s].second;
        //                 rel[s].second=t;
        //             } else {
        //                 rel[s].first=t;
        //             }
        //         } else rel[s].second = t;
        //     }
        // }