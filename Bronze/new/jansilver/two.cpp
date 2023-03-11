#include <bits/stdc++.h>
using namespace std;

int c[1501][1501];

void dfs(int n, bool (&a)[1501][1501], int r[1501], int d[1501], int i, int j) {
    if(i<0||j<0) return;
    if(i==n-1&&j==n-1) {
        if(a[i][j]) c[i][j]=r[n-1];
        else c[i][j]=d[n-1];
    } else if(i==n-1) {
        if(!a[i][j]) c[i][j] = d[j];
        else c[i][j] = c[i][j+1];
    } else if(j==n-1) {
        if(a[i][j]) c[i][j] = r[j];
        else c[i][j] = c[i+1][j];
    } else {
        if(a[i][j]) c[i][j] = c[i][j+1]; 
        else c[i][j] = c[i+1][j];
    }
    dfs(n, a, r, d, i, j-1);
    dfs(n, a, r, d, i-1, j);

}

int main() {
    int n;
    cin>>n;
    bool a[1501][1501];
    int r[1501], d[1501];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            char c;
            cin>>c;
            if(c=='R') a[i][j] = true;
            else a[i][j] = false;
        }
        cin>>r[i];
    }
    for(int i=0;i<n;i++) cin>>d[i];
    int q;
    cin>>q;
    pair<int, int> s[q];
    for(int i=0;i<q;i++) {
        int x,y;
        cin>>x>>y;
        s[i] = {x-1,y-1};
    }
    int cost = 0;
    dfs(n, a, r, d, n-1, n-1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cost+=c[i][j];
        }
    }
    cout<<cost<<endl;
    for(int i=0;i<q;i++) {
        if(a[s[i].first][s[i].second]) {
            cost-=r[s[i].first];
            cost+=d[s[i].second];
        } else {
            cost-=d[s[i].second];
            cost+=r[s[i].first];
        }
        cout<<cost<<endl;
        a[s[i].first][s[i].second] = !a[s[i].first][s[i].second];
    }

}

// dfs and precompute possible rewards at each while adding the total
// when we change set the value to the cost of the new direction and sub/add