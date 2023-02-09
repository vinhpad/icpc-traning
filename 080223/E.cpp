#include <bits/stdc++.h>

#ifdef LOCAL

auto &&cin = std::ifstream(LOCAL ".in");
auto &&cout = std::ofstream(LOCAL ".out");

#else

auto &cin = [] () -> std::istream& {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return std::cin;
}();
using std::cout;

#endif

using Long = long long;

int cache[1000000];

Long f(Long x)
{
    Long dep = 0;
    while (x >= 1000000) {
      Long r = x / 3;
      Long d = x - r * 3;
      dep += d;
      x -= d;
      x /= 3;
      ++dep;
    }
    return dep + cache[x];
}

Long maxF(Long l, Long r)
{
    Long res = 0;
    Long ld = l % 3;
    Long rd = r % 3;
    if (ld != 0) {res = f(ld == 1 && l < r ? l + 1 : l); l += 3 - ld;}
    if (rd != 2) {res = std::max(f(r), res); r -= rd + 1;}
    if (l > r) return res;
    return std::max(res, maxF(l / 3, r / 3) + 3);
}

int main()
{
    cache[0] = 1;
    for (int i = 1; i < 1000000; ++i) {
      if (i % 3 == 0) cache[i] = cache[i / 3] + 1;
      else cache[i] = cache[i - 1] + 1;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      Long l, r;
      cin >> l >> r;
      cout << maxF(l, r) << '\n';
    }
    return 0;
}