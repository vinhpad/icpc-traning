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

int n, k;
vector< pair < int, int > > line;
int pre[maxn];
int maxLen;

void process(vector< pair<int, int> > v) {
    vector<int> res;
    for(auto x: v) {
        res.pb(x.F);
        res.pb(x.S);
        res.pb(x.S + 1);
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    for(auto x: v) {
        int id = lower_bound(res.begin(), res.end(), x.F) - res.begin();
        pre[id] ++;
        id = lower_bound(res.begin(), res.end(), x.S + 1) - res.begin();
        pre[id] --;
    }
    maxLen = res.size();
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        int a, b;
        cin >> a >> b;
        if(b - a + 1 >= k) ++ ans;
        else {
            a %= k;
            b %= k;
            if(a <= b) {
                line.pb({a, b});
            }
            else {
                line.pb({a, k - 1});
                line.pb({0,b});
            }
        }
    }
    process(line);
    for(int i = 1; i <= maxLen; ++ i) {
        pre[i] += pre[i - 1];
    }
    cout << ans + *max_element(pre, pre + maxLen + 1);
    Time;
    return 0;
}
