#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ones(x) __builtin_popcountll(x)
#define int long long
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+5;

bool cw(pii a, pii b, pii c){
    return a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second) > 0;
}

bool ccw(pii a, pii b, pii c){
    return a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second) < 0;
}

bool collinear(pii a, pii b, pii c){
    return a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second) == 0;
}

void convex_hull(vpii &a){
    if(a.size()<=2) return;
    sort(all(a));
    // now a[0] is a1 and a[n-1] is an
    int n = a.size();
    pii a1 = a[0], an = a[n-1];
    // now a1 and an are the leftmost and rightmost piis
    vpii up, down;
    up.pb(a1);
    down.pb(a1);
    for(int i = 1; i<n; i++){
        // now i have to check if the pii is above or below the line a1-an
        if(i==n-1 || !ccw(a1, a[i], an)){
            // if the pii is below the line then it is not a part of the convex hull
            // so i will remove it
            while(up.size()>=2 && ccw(up[up.size()-2], up[up.size()-1], a[i])){
                up.pop_back();
            }
            up.pb(a[i]);
        }
        if(i==n-1 || !cw(a1, a[i], an)){
            // if the pii is above the line then it is not a part of the convex hull
            // so i will remove it
            while(down.size()>=2 && cw(down[down.size()-2], down[down.size()-1], a[i])){
                down.pop_back();
            }
            down.pb(a[i]);
        }
    }
    // now up and down contains the piis of the convex hull
    a.clear();
    for(int i=0;i<up.size();i++) a.pb(up[i]);
    for(int i=down.size()-2;i>0;i--) a.pb(down[i]);
    // now a contains the piis of the convex hull
    sort(all(a));
    a.resize(unique(all(a))-a.begin());
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    vpii a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    convex_hull(a);
    // now a contains the piis of the convex hull
    for(auto i:a){
        cout<<i.first<<" "<<i.second<<"\n";
    }

    return 0;
}
