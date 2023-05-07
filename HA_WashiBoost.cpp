#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define int ll

using namespace std;
using ll = long long;

const int N=5e4+10,MOD=1e9+7;
const int di[8]={1,-1,0,0,-1,1,1,-1},dj[8]={0,0,1,-1,1,1,-1,-1};

vector<int> g[N];
int dp[32][N],b[7],a[N],mul[32];
int n,k,h,bit;

void dfs(int v,int p){
    int ch=1;
    for(auto x:g[v]){
        if(x==p) continue;
        ch=0;
        dfs(x,v);
        for(int i=0;i<bit;i++){
            dp[i][v]=max(dp[i][v],dp[i][x]);
        }
    }
    if(ch){
        for(int i=0;i<bit;i++) dp[i][v]=dp[i][0];
    }
    for(int i=0;i<bit;i++){
        for(int j=0;j<bit;j++){
            if(j&i) continue;
            dp[i|j][v]=max(dp[i|j][v],dp[i][v]*mul[j]);
        }
    }
    for(int i=0;i<bit;i++){
        if(dp[i][v]<a[v]){
            dp[i][v]=-2e9;
        }
        else dp[i][v]+=a[v]/2;
    }
    for(int i=0;i<bit;i++){
        for(int j=0;j<bit;j++){
            if(j&i) continue;
            if(dp[i][v]<0) continue;
            dp[i|j][v]=max(dp[i|j][v],dp[i][v]*mul[j]);
        }
    }
    return ;
}

void sol(){
    cin >> n >> k >> h;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<k;i++) cin >> b[i];
    sort(b,b+k);
    bit=(1<<k);
    for(int i=0;i<(1<<k);i++){
        dp[i][0]=h;
        mul[i]=1;
        for(int j=0;j<k;j++){
            if((1<<j)&i){
                dp[i][0]*=b[j];
                mul[i]*=b[j];
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int mx=0;
    for(int i=0;i<(1<<k);i++) mx=max(mx,dp[i][1]);
    cout << (mx==0?-1:mx) << "\n";
    return ;
}

int32_t main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int q=1;
    // cin >> q;
    while(q--){
        sol();
    }
    return 0;
}
