/** Nguyen Anh Tu **/
#include <bits/stdc++.h>
#define maxn 100005
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

int n, a[maxn];

int main(){
  ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
  if(fopen(task".inp","r")){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
  }
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];
  int mx1 = 0, mx2 = 0;
  sort(a + 1, a + n + 1);
  cout << max(a[n], 0) + max(a[n - 1], 0);
  Time;
  return 0;
}