#include <map>
#include <set>
#include <array>
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
using std::array;
using std::string;
using std::vector;

using Long = long long;
#define int Long

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

constexpr int NMAX = 15;
constexpr int MMAX = 200000;
constexpr int RAW_MAX = 10;
constexpr int AMT_MAX = 100000000;

int n, m;
int c[MMAX+1];
vector<int> raws;
vector<int> rawsAmt;
vector<int> recipe[MMAX+1];

vector<vector<int>> ultRecipe;

signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      cin >> c[i];
      if (c[i] == 0) {
        raws.push_back(i);
        rawsAmt.push_back(0);
        cin >> rawsAmt.back();
      }
      else {
        recipe[i].resize(c[i]);
        for (int j = 0; j < c[i]; ++j) {
          cin >> recipe[i][j];
        }
      }
    }

    ultRecipe.resize(n + 1);

    vector<int> amt(m + 1);
    for (int i = 1; i <= n; ++i) {
      fill(amt.begin(), amt.end(), 0);
      amt[i] = 1;
      for (int j = i; j <= m; ++j) {
        if (c[j] != 0) {  
          for (int k = 0; k < c[j]; ++k) {
            amt[recipe[j][k]] = min(AMT_MAX + 1, amt[recipe[j][k]] + amt[j]);
          }
          amt[j] = 0;
        }
      }
      ultRecipe[i].resize(raws.size());
      for (int j = 0; j < raws.size(); ++j) {
        ultRecipe[i][j] = amt[raws[j]];
      }
    }

    int res = 0;
    vector<int> curAmt(raws.size());
    for (int mask = 0; mask < 1 << n; ++mask) {
      fill(curAmt.begin(), curAmt.end(), 0);
      int cnt = 0;
      bool ok = true;
      for (int i = 1; i <= n; ++i) {
        if ((mask >> (i - 1)) & 1) {
          ++cnt;
          for (int j = 0; j < raws.size(); ++j) {
            curAmt[j] += ultRecipe[i][j];
            if (curAmt[j] > rawsAmt[j]) {
              ok = false;
              break;
            }
          }
        }
      }
      if (ok) res = max(res, cnt);
    }

    print(res);

    return 0;
}
