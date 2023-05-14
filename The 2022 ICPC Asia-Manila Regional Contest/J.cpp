#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::min;
using std::max;
using std::string;
using std::vector;

using Long = long long;

template<typename T>
void print(const T& x)
{
    cout << x;
}

template<typename T, typename ...Ts>
void print(const T& x, const Ts& ...xs)
{
    print(x);
    print(xs...);
}

template<typename ...Ts>
void println(const Ts&... xs)
{
    print(xs..., '\n');
}

struct Point
{
    int r, c;
};

void connect(vector<string>& board, Point a, Point b)
{
    for (int i = min(a.r, b.r); i <= max(a.r, b.r); ++i) {
      board[i][a.c] = '#';
    }
    for (int i = min(a.c, b.c); i <= max(a.c, b.c); ++i) {
      board[b.r][i] = '#';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<Point> lands;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
      cin >> board[i];
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == '#') {
          lands.push_back({i, j});
        }
      }
    }

    Point a = lands[0], b = lands[1], c = lands[2];

    int u = min(a.r, b.r);
    int d = max(a.r, b.r);
    int l = min(a.c, b.c);
    int r = max(a.c, b.c);

    if (u <= c.r && c.r <= d && l <= c.c && c.c <= r) {
      connect(board, a, c);
      connect(board, b, c);
    }
    else {
      Point cnt = {std::clamp(c.r, u, d), std::clamp(c.c, l, r)};
      connect(board, a, cnt);
      connect(board, b, cnt);
      connect(board, c, cnt);
    }

    for (auto& row : board) {
      println(row);
    }

    return 0;
}
