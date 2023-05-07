#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define pii pair<int,int>

using namespace std;
using ll = long long;

const int N=1e5+10,MOD=1e9+7;
const int di[8]={1,-1,0,0,-1,1,1,-1},dj[8]={0,0,1,-1,1,1,-1,-1};

struct A{
    int x,y;
}a[2555];
ll qs[2555][2555];
vector<int> X,Y;
void sol(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        a[i]={x,y};
        X.push_back(x);
        Y.push_back(y);
    }
    sort(all(X));
    sort(all(Y));
    X.resize(unique(all(X))-X.begin());
    Y.resize(unique(all(Y))-Y.begin());
    for(int i=1;i<=n;i++){
        a[i].x=upper_bound(all(X),a[i].x)-X.begin();
        a[i].y=upper_bound(all(Y),a[i].y)-Y.begin();
        qs[a[i].x][a[i].y]++;
    }
    for(int i=1;i<=2501;i++){
        for(int j=1;j<=2501;j++){
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int si=min(a[i].x,a[j].x);
            int ei=max(a[i].x,a[j].x);
            int sj=min(a[i].y,a[j].y);
            int ej=max(a[i].y,a[j].y);
            ll l=qs[si-1][ej]-qs[si-1][sj-1];
            ll r=(qs[2501][ej]-qs[2501][sj-1])-(qs[ei][ej]-qs[ei][sj-1]);
            ans+=(l+1)*(r+1);
        }
    }
    cout << ans+1+n << "\n";
    return ;
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int q=1;
    // cin >> q;
    while(q--){
        sol();
    }
    return 0;
}
