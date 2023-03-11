#include <bits/stdc++.h>
using namespace std;

struct Cow {
    bool dir;
    int x;
    int y;
    int id;
    Cow(bool dir, int x, int y, int id) : dir(dir), x(x), y(y), id(id) {};
};

bool eastCow(const Cow& c1, const Cow& c2) {
    return (c1.y<c2.y);
} 

bool northCow(const Cow& c1, const Cow& c2) {
    return (c1.x<c2.x);
} 

int main() {
    int n;
    cin>>n;
    vector<Cow> north, east;
    vector<int> a(n);
    fill(a.begin(), a.end(), -1);
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        bool dir = c=='E' ? true : false;
        int x,y;
        cin>>x>>y;
        if(dir) east.push_back(Cow(dir, x, y, i));
        else north.push_back(Cow(dir, x, y, i));
    }
    sort(north.begin(), north.end(), northCow);
    sort(east.begin(), east.end(), eastCow);
    for(int i=0;i<north.size();i++) {
        // check lowest stopping point from north to east cows
        bool t = false;
        for(int j=0;j<east.size();j++) {
            if(north[i].x>east[j].x&&north[i].y<east[j].y&&a[east[j].id]==-1) {
                if(east[j].y-north[i].y==north[j].x-east[i].x) continue;
                if(east[j].y-north[i].y<north[j].x-east[i].x) {
                    a[east[j].id]=north[i].x-east[j].x;
                    continue;
                } else if (east[j].y-north[i].y>north[j].x-east[i].x) {
                    a[north[i].id]=east[j].y-north[i].y;
                    cout<<north[i].x<<' '<<north[i].y<<' '<<east[j].x<<' '<<east[j].y<<' ';
                    t=true;
                    break;
                }
            }
        }
    }
    // check north cows in front and east cows in front
    // for(int i=0;i<north.size();i++) {
    //     for(int j=0;j<north.size();j++) {
    //         if(i==j) continue;
    //         if(north[i].x==north[j].x) {
    //             int min = north[i].y<north[j].y ? i : j;
    //             int max = north[i].y<north[j].y ? j : i;
    //             if(a[north[min].id]==-1) a[north[min].id]=north[max].y-north[min].y;
    //             else a[north[min].id]=std::min(north[max].y-north[min].y, a[north[min].id]);
    //         }
    //     }
    // }
    // for(int i=0;i<east.size();i++) {
    //     for(int j=0;j<east.size();j++) {
    //         if(i==j) continue;
    //         if(east[i].y==east[j].y) {
    //             int min = east[i].y<east[j].y ? i : j;
    //             int max = east[i].y<east[j].y ? j : i;
    //             if(a[east[min].id]==-1) a[east[min].id]=east[max].x-east[min].x;
    //             else a[east[min].id]=std::min(east[max].x-east[min].x, a[east[min].id]);
    //         }
    //     }
    // }
    for(int i=0;i<n;i++) {
        if(a[i]==-1) cout<<"Infinity"<<endl;
        else cout<<a[i]<<endl;
    }
}