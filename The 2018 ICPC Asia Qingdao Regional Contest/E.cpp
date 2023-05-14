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

int n;
long long m;
int a[maxn];
long long d[maxn];

bool check(long long x) {
    long long res = 0;
    for(int i = 1; i <= n; ++ i) d[i] = 0;
    for(int i = 1; i <= n; ++ i) {
        if(d[i] < x) {
            long long u = (x - d[i] + a[i] - 1) / a[i];
            d[i] += u * a[i];
            res += (u * 2 - 1);
            if(res > m) return 0;
            d[i + 1] += (u - 1) * a[i + 1];
        }
        else {
            ++ res;
        }
    }
    return 1;
}

void Solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    long long l = 0, r = 1e18;
    while(l < r - 1){
        if(check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << '\n';
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

