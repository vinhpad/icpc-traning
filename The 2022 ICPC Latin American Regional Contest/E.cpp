#include "bits/stdc++.h"
#define rep(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
int N, K, E;
bool used[1005];
int solve(int left,int right) {
    int result = left + right;
    rep(x,1,left) if(!used[x])
    {
        used[x] = true;
        result = min(result, left + right - x);
        rep(i,1,right) if(!used[i] && !used[right-i] && i!=right-i) {
                result = min(result,left - x );
                break;
        }


        rep(y,1,left-x) if (!used[y]) {
            used[y] = true;
            result = min(result,left + right - x - y);
            rep(i,1,right) if(!used[i] && !used[right-i] && i!=right-i) {
                result = min(result,left - x - y );
                break;
            }
            used[y] = false;
        }
        used[x] = false;
    }
    return result;
}

void process() {
    cin >> N >> K >> E;
    int F = N - K - E;
    for(int i=0;i<=1000;++i) used[i] = false;
    used[K] = true;
    if(F!=K&&F!=E&&K!=E) {
        cout << 0 << endl;
        return;
    }
    cout << min(solve(E,F), solve(F,E));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    process();
}
