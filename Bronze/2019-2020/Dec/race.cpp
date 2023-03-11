#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x) {
    int speed = 0;
    int count = 0;
    int left = n;
    int exclude = ((x)*(x+1)/2);
    while(left>0) {
        int spaces = ((speed+1)*(speed+2)/2)-exclude;
        int sspaces = (speed*(speed+1)/2)-exclude;
        if(speed+1+spaces<=left+x-1) {
            speed++;
            left-=speed;
            count++;
        } else if(sspaces<=left+x-1) {
            left-=speed;
            count++;
        } else {
            speed--;
            left-=speed;
            count++;
        }
    }
    cout<<count<<endl;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    int a[k];
    for(int i=0;i<k;i++) cin>>a[i];
    for(int i=0;i<k;i++) solve(n, a[i]);
}

// you are OVERCOMPLICATING THIS
// THE SOLUTION YOU THOUGHT OF AT FIRST WILL WORK
// FIND THE MAXIMUM INCREASE until increase is not possible
// calculate the movements until decrease required
// calculate number of movements for decrease