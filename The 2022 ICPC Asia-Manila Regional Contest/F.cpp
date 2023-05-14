/** Nguyen Anh Tu **/
#include <bits/stdc++.h>
#define maxn 200005
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
long long sum = 0;
set< pair< long long, int > > s;
set< int > id;
long long a[maxn];

void process(auto it, auto it1) {
    int i = (*it).S;
    ++it1;
    if(it1 != id.end()) {
        s.erase({a[*it1], *it1});
        a[*it1] += a[i]/2;
        s.insert({a[*it1], *it1});
    }
    else {
        sum -= a[i]/2;
    }
    -- it1;
    if(it1 != id.begin()) {
        -- it1;
        s.erase({a[*it1], *it1});
        a[*it1] += a[i]/2;
        s.insert({a[*it1], *it1});
        ++ it1;
    }
    else {
        sum -= a[i]/2;
    }
    s.erase({a[i], i});
    id.erase(i);
    sum -= (a[i] & 1);
    cout << i << ' ' << a[i] << '\n';

}

void update_hegemony() {
    auto it = s.end();
    -- it;
    it = s.lower_bound({(*it).F, 0});
    auto it1 = id.lower_bound((*it).S);
    process(it, it1);
}

void update_nhegemony() {
    auto it = s.begin();
    auto it1 = id.lower_bound((*it).S);
    process(it, it1);
}

bool hegemony() {
    auto it = s.end();
    --it;
    return sum >= (*it).F * 2;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
        id.insert(i);
        s.insert({x, i});
    }
    for(int i = 1; i <= n; ++ i) {
        if(hegemony()) {
            update_hegemony();
        }
        else {
            update_nhegemony();
        }
    }
    Time;
    return 0;
}
