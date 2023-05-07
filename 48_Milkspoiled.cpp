#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define pii pair<int,int>

using namespace std;
using ll = long long;

const int N=1e5+10,MOD=1e9+7;
const int di[8]={1,-1,0,0,-1,1,1,-1},dj[8]={0,0,1,-1,1,1,-1,-1};

vector<pii> g;

void sol(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >> u >> v;
        g.push_back({u,y-x});
        g.push_back({v+1,z-y});
    }
    sort(all(g));
    ll ans=x*n,mx=ans;
    for(auto v:g){
        ans+=v.second;
        mx=max(mx,ans);
    }
    cout << mx << "\n";
    g.clear();
    return ;
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int q=1;
    cin >> q;
    while(q--){
        sol();
    }
    return 0;
}