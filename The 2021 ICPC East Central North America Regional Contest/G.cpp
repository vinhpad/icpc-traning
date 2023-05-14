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

string a[3];

long long toInt(string s) {
    long long res = 0;
    for(auto x: s) {
        res = (res * 10 + x - '0');
    }
    return res;
}

bool Solve(int u, int v, int type) {
    long long res;
    int pos;
    for(int x = 0 ; x < 3; ++ x) if(x != u && x != v) {
        res = toInt(a[x]);
        pos = x;
        break;
    }
    for(int i = 0; i < a[u].size(); ++ i) {
        for(int j = 0; j < a[v].size(); ++ j) {
            string s = a[u], t = a[v];
            string s1 = s.substr(0, i);
            string t1 = t.substr(0, j);
            s.erase(0, i);
            t.erase(0, j);
            t1 += s;
            s1 += t;
            long long a1 = toInt(t1);
            long long a2 = toInt(s1);
            if(pos == 2) {
                if(type == 1) {
                    if(a1 + a2 == res) {
                        cout << a1 <<  " + " << a2 << " = " << res;
                        return true;
                    }
                }
                else {
                    if(a1 * a2 == res) {
                        cout << a1 <<  " * " << a2 << " = " << res;
                        return true;
                    }
                }
            }
            else {
                if(pos == 0) swap(a1, res);
                if(type == 1) {
                    if(a1 + res == a2) {
                        cout << a1 <<  " + " << res << " = " << a2;
                        return true;
                    }
                }
                else {
                    if(a1 * res == a2) {
                        cout << a1 <<  " * " << res << " = " << a2;
                        return true;
                    }
                }
                if(pos == 0) swap(a1, res);
            }
        }
    }
    return false;

}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    string s;
    int run = 0, type = 0;
    getline(cin, s);
    for(auto x: s) {
        if('0' <= x && x <= '9') {
            a[run] = a[run] + x;
        }
        else if(x == ' ') ++ run;
        else {
            if(x == '+') type = 1;
            else if(x == '*') type = 2;
            -- run;
        }
    }
    for(int i = 0; i < 3; ++ i){
        for(int j = i + 1; j < 3; ++ j) {
            if(Solve(i, j, type)) return 0;
        }
    }
    return 0;
}

