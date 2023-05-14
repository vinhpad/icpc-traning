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

struct V2
{
    int x, y;
};

V2 operator + (V2 a, V2 b)
{
    return {a.x + b.x, a.y + b.y};
}

constexpr int NMAX = 50, MMAX = NMAX;

int n, m;

int a[NMAX+1][MMAX+1];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] != -1)
        v.push_back(a[i][j]);
    }
    std::sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] != -1)
        a[i][j] = std::lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
    
    int ans = m * n;

    int cur;
    int moved;

    moved = 0;
    cur = 0;
    for (int l = 2; l <= n + m; ++l) {
      int high = cur;
      for (int i = max(1, l - m); i <= min(n, l - 1); ++i) {
        int j = l - i;
        if (a[i][j] != -1) ++high;
      }
      for (int i = max(1, l - m); i <= min(n, l - 1); ++i) {
        int j = l - i;
        if (a[i][j] == -1) {}
        else if (a[i][j] >= cur && a[i][j] < high) {}
        else ++moved;
      }
      cur = high;
    }
    ans = min(ans, moved);
    
    moved = 0;
    cur = 0;
    for (int l = n + m; l >= 2; --l) {
      int high = cur;
      for (int i = max(1, l - m); i <= min(n, l - 1); ++i) {
        int j = l - i;
        if (a[i][j] != -1) ++high;
      }
      for (int i = max(1, l - m); i <= min(n, l - 1); ++i) {
        int j = l - i;
        if (a[i][j] == -1) {}
        else if (a[i][j] >= cur && a[i][j] < high) {}
        else ++moved;
      }
      cur = high;
    }
    ans = min(ans, moved);

    moved = 0;
    cur = 0;
    for (int k = 1 - m; k <= n - 1; ++k) {
      int high = cur;
      for (int i = max(1, k + 1); i <= min(n, k + m); ++i) {
        int j = i - k;
        if (a[i][j] != -1) ++high;
      }
      for (int i = max(1, k + 1); i <= min(n, k + m); ++i) {
        int j = i - k;
        if (a[i][j] == -1) {}
        else if (a[i][j] >= cur && a[i][j] < high) {}
        else ++moved;
      }
      cur = high;
    }
    ans = min(ans, moved);

    moved = 0;
    cur = 0;
    for (int k = n - 1; k >= 1 - m; --k) {
      int high = cur;
      for (int i = max(1, k + 1); i <= min(n, k + m); ++i) {
        int j = i - k;
        if (a[i][j] != -1) ++high;
      }
      for (int i = max(1, k + 1); i <= min(n, k + m); ++i) {
        int j = i - k;
        if (a[i][j] == -1) {}
        else if (a[i][j] >= cur && a[i][j] < high) {}
        else ++moved;
      }
      cur = high;
    }
    ans = min(ans, moved);

    print(ans);

    return 0;
}
