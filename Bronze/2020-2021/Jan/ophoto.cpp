#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int odd=0,even=0,oc=0,ec=0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x%2==1) odd++;
        else even++;
    }
    bool e = true;
    int min = std::min(odd, even);
    odd-=min;even-=min;
    oc+=min;ec+=min;
    if(even>0) ec++;
    if(odd>0) {
        if(odd%3==0)oc+=(int)(odd/3)*2;
        else if(odd%3==1)oc+=(int)(odd/3)*2-1;
        else if(odd%3==2)oc+=(int)(odd/3)*2+1;
    }
    int ret = oc+ec;
    cout<<ret<<endl;
}