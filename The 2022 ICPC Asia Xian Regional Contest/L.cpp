/** Nguyen Anh Tu **/
#include <bits/stdc++.h>
#define maxn 1000005
#define maxc 1000000007
#define MOD 1000000007
#define task ""
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)
#define mid ((l + r)/2)
#define Time   cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC

using namespace std;

int n, h[maxn];
vector<int> a[maxn], v[maxn];

void dfs(int u, int par = -1) {
  h[u] = 1;
  for(auto v: a[u]) if(v != par){
      dfs(v, u);
      h[u] = max(h[u], h[v] + 1);
    }
}

void Solve() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    a[i].clear();
    v[i].clear();
  }
  for(int i = 2; i <= n; ++ i) {
    int u;
    cin >> u;
    a[i].pb(u);
    a[u].pb(i);
  }
  dfs(1);
  for(int i = 1; i <= n; ++ i) {
    v[h[i]].pb(i);
  }
  int mx = *max_element(h + 1, h + n + 1);
  int ans = maxc;
  for(int i = 0; i <= mx; ++ i) {
    ans = min(ans, i + (int)v[i + 1].size());
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
  if(fopen(task".inp","r")){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
  }
  int t;
  cin >> t;
  while(t --) {
    Solve();
  }
  Time;
  return 0;
}