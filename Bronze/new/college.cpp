#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long maxVal = a[0];
    long long tuition = a[0];
    int ma = *max_element(a,a+n);
    int su[ma], pref[ma];
    fill(su,su+ma,0);
    for(int i=0;i<n;i++) su[a[i]-1]++;
    pref[0] = su[0];
    for(int i=1;i<ma;i++) pref[i]=su[i]+pref[i-1];
    for(int i=1;i<n;i++) {
        long long newVal = 0;
        if(a[i]==1) newVal=pref[ma-1];
        else newVal = pref[ma-1] - pref[a[i]-2];
        newVal*=a[i];
        
        if(newVal>maxVal) {
            maxVal=newVal;
            tuition=a[i];
        } if(newVal==maxVal) {
            tuition=tuition<a[i] ? tuition : a[i];
        }
    }
    cout<<maxVal<<' '<<tuition<<endl;
}