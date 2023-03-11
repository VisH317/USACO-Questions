#include <bits/stdc++.h>
using namespace std;

bool grid[1001][1001] = {false};

bool validPosition(int x, int y) {
    return x>=0 && x<=1001 && y>=0 && y<=1001;
}

int getAdj(int x, int y) {
    int c=0;
    if(validPosition(x,y)) {
        if(x!=1000&&grid[x+1][y])c++;
        if(y!=1000&&grid[x][y+1])c++;
        if(x!=0&&grid[x-1][y])c++;
        if(y!=0&&grid[x][y-1])c++;
    }
    return c;
}

int findAdd(int x, int y) {
    int count=0;
    if(validPosition(x,y)) {
        int a = getAdj(x+1,y);
        int b = getAdj(x,y+1);
        int c = getAdj(x-1,y);
        int d = getAdj(x,y-1);
        int e = getAdj(x,y);
        count+=a==3?1:a==4?-1:0;
        count+=b==3?1:b==4?-1:0;
        count+=c==3?1:c==4?-1:0;
        count+=d==3?1:d==4?-1:0;
        count+=e==3?1:d==4?-1:0;
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    int count = 0;
    int a[n];
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        grid[x][y]=true;
        int c = findAdd(x,y);
        count+=c;
        a[i]=count;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<endl;
}