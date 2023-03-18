#include "bits/stdc++.h"
#define MAXN 200000
using namespace std;
 
int dp[MAXN];
vector<int> tree[MAXN];
 
int calc(int u,int par) {
    if(tree[u].size()==1 && u != 1) {
        return dp[u] = 1;
    }
 
    int f=0,s=0;
 
    for(int v : tree[u]) if(v!=par) {
        calc(v,u);
        if(f < dp[v]) {
            s = f;
            f = dp[v];
        } else {
            if(s < dp[v]) {
                s = dp[v];
            }
        }
    }
 
    dp[u] = max(f,s+1);
    return dp[u];
}
 
void solve() {
 
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        dp[i] = 0;
        tree[i].clear();
    }
    for(int i=1;i<=n;++i) {
        int x;cin >> x;
        if(i==1) continue;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
 
    calc(1,0);
    cout << dp[1] << endl;
}
 
int main() {
    int numQue;cin >> numQue;
    while(numQue--) {
        solve();
    }
}
