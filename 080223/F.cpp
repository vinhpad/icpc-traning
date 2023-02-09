#include <bits/stdc++.h>

#ifdef LOCAL

auto &&cin = std::ifstream(LOCAL ".in");
auto &&cout = std::ofstream(LOCAL ".out");

#else

using std::cin;
using std::cout;

#endif

constexpr int NMAX = 1000;

char a[NMAX][4];

bool twoable(const char *team)
{
  return team[0] == team[1] || team[1] == team[2] || team[0] == team[2];
}

int main()
{
  int n, c1, c2;
  cin >> n >> c1 >> c2;
  c1 = std::min(c1, c2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (c1 * 2 <= c2) cout << n * 3 * c1 << '\n';
  else {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (twoable(a[i])) ans += c1 + c2;
      else ans += c1 * 3;
    }
    cout << ans;
  }
  return 0;
}