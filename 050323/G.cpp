#include "bits/stdc++.h"

#define rep(i, l, r) for(int i=l;i<r;++i)
#define loop(i, times) for(int i=0;i<times;++i)
#define maxN 2005
using namespace std;
int N, M, K;
vector<pair<int, int> > lines;
int dp[maxN][maxN];

void solve(int query_id) {
    cin >> N >> M >> K;
    lines.clear();
    memset(dp, 0, sizeof dp);
    loop(i, M) {
        int l, r;
        cin >> l >> r;
        lines.push_back({l, r});
    }

    sort(begin(lines), end(lines),
         [&](pair<int, int> x, pair<int, int> y) {
             return (x.first < y.first || (x.first == y.first && x.second > y.second));
         }
    );

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) dp[i][j] = 0;
    }

    int position = 0, max_len = 0;
    for (int i = 0; i < N; ++i) {

        while (position < M && lines[position].first == i + 1) {
            max_len = max(max_len, lines[position].second - lines[position].first + 1);
            position++;
        }

        for (int j = 0; j <= K; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + max_len][j + 1] = max(dp[i + max_len][j + 1], dp[i][j] + max_len);
        }
        if (max_len) --max_len;
    }

    cout << "Case #" << query_id << ": " << dp[N][K] << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numQuery;
    cin >> numQuery;
    rep(i,1,numQuery+1) {
        solve(i);
    }
}
