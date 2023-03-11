#include <bits/stdc++.h>
using namespace std;

int n;
string years[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
int y[101];
bool isPrev[101];
string first[101], second[101];

int countYears(int i, int n, int cur, int yearIdx) {
    cur+=isPrev[i]?-1*(yearIdx+12-y[i]):(y[i]+12-yearIdx);
    if(first[i]=="Elsie") return abs(cur);
    bool t = true;
    int x;
    for(int j=0;j<n;j++) {
        if(second[j].compare(first[i])==0) {
            x = countYears(j,n,cur,y[i]);
            if(x!=-1) return x;
            t=false;
        }
    }
    return -1;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        string w,f,s,ye,p;
        cin>>f;
        cin>>w;
        cin>>w;
        cin>>p;
        cin>>ye;
        cin>>w>>w;
        cin>>s;
        first[i]=f;second[i]=s;
        isPrev[i]=p=="previous" ? true : false;
        y[i] = distance(years, find(years, years+12, ye))+1;
    }
    int ret;
    for(int i=0;i<n;i++) {
        if(second[i].compare("Bessie")==0) {
            ret = countYears(i,n,0,1);
            if(ret!=-1) break;
        }
    }
    cout<<ret<<endl;
}