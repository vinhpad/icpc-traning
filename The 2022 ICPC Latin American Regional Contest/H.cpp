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

int n, m, res, cur, matchX[maxn], used[maxn], w[maxn];
vector<int> ke[maxn];
string s[maxn];
vector<string> t[maxn];
map<string, int> M;
int pos[maxn];
bool bs[305][305];

bool DFS(int u)
{
    if (used[u] == cur) return 0;
    used[u] = cur;
    for (int v : ke[u])
        if (matchX[v] == 0 || DFS(matchX[v]))
        {
            matchX[v] = u;
            return 1;
        }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> s[i];
        M[s[i]] = i + n;
        pos[i] = maxc;
        for(int j = 1; j <= n; ++ j) bs[i][j] = 1;
    }
    cin >> m;
    for(int i = 1; i <= m; ++ i) {
        int k;
        cin >> k >> w[i];
        vector<int> d(n + 1, 0);
        for(int j = 1; j <= k; ++ j) {
            string temp;
            cin >> temp;
            int id = M[temp];
            pos[id] = max(pos[id], w[i]);
            d[id - n] = 1;
        }
        for(int j = 1; j <= n; ++ j) {
            if(!d[j]) {
                bs[w[i]][j] = 0;
            }
        }
    }
    for(int i = 1; i <= m; ++ i) {
        for(auto str: t[i]) {
            int id = M[str];
            if(pos[id] <= w[i] && bs[w[i]][id - n] == 1) {
                ke[id].pb(w[i]);
                ke[w[i]].pb(id);
            }
        }
    }
    for(int i = 1; i <= n; ++ i) {
        if(!ke[i].size()) {
            for(int j = n + 1; j <= 2 * n; ++ j) if(pos[j] <= i && bs[i][j - n] == 1) {
                ke[i].pb(j);
                ke[j].pb(i);
            }
        }
    }
    for(cur = 1; cur <= 2 * n; ++ cur) DFS(cur);
    for(int i = 1; i <= n; ++ i) cout << s[matchX[i] - n] << ' ';
    Time;
    return 0;
}
