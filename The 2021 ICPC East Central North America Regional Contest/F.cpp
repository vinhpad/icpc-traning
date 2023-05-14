/** Nguyen Anh Tu **/
#include <bits/stdc++.h>
#define maxn 105
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

struct Circle{
    double x, y;
    double r;
    double s;
} a[maxn];

struct Data {
    int id;
    double x, y;
    double r;
    double s;
    int cnt;
} root[maxn];

double dis(Circle a, Circle b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double Find(){
    double res = 1e10;
    for(int i = 1; i <= n; ++ i) {
        for(int j = i + 1; j <= n; ++ j) {
            res = min(res, (dis(a[i], a[j]) - a[i].r - a[j].r + 1e-6)/(a[i].s + a[j].s));
        }
    }
    return max(res, 0.0);
}

int get_root(int u) {
    return !root[u].id ? u : root[u].id = get_root(root[u].id);
}

void add(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    if(u != v) {
        root[u].id = v;
    }
}

bool compress(Circle a[], int &n) {
    for(int i = 1; i <= n; ++ i) {
        root[i] = {0, a[i].x, a[i].y, a[i].r * a[i].r, a[i].s, 1};
    }
    for(int i = 1; i <= n; ++ i) {
        for(int j = i + 1; j <= n; ++ j) {
            if(dis(a[i], a[j]) <= (a[i].r + a[j].r)) {
                add(i, j);
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++ i) {
        int u = i;
        int v = get_root(i);
        if(u != v){
            root[v].x = (root[u].x * root[u].cnt + root[v].x * root[v].cnt) / (root[u].cnt + root[v].cnt);
            root[v].y = (root[u].y * root[u].cnt + root[v].y * root[v].cnt) / (root[u].cnt + root[v].cnt);
            root[v].r = root[u].r + root[v].r;
            root[v].s = max(root[u].s, root[v].s);
            root[v].cnt += root[u].cnt;
        }
    }
    for(int i = 1; i <= n; ++ i) {
        root[i].id = get_root(i);
        if(root[i].id == i) a[++ cnt] = {root[i].x, root[i].y, sqrt(root[i].r), root[i].s};
    }
    n = cnt;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i].x >> a[i].y >> a[i].r >> a[i].s;
    }
    for(int i = n; i >= 1; -- i) {
        if(n == 1) break;
        double nextTime = Find();
        for(int j = 1; j <= n; ++ j) {
            a[j].r += nextTime * a[j].s;
        }
        compress(a, n);
    }
    cout << fixed << setprecision(8) << a[1].x << ' ' << a[1].y << ' ' << a[1].r;
    Time;
    return 0;
}
