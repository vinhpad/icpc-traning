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

constexpr int NMAX = 100;

int n, p1, u1, p2, u2;
int lis1[NMAX+1], lis2[NMAX+1], pin1[NMAX+1], pin2[NMAX+1], ord2[NMAX+1];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    cin >> p1 >> u1;
    n = p1 + u1;
    for (int i = 1; i <= n; ++i) {
      cin >> lis1[i];
      pin1[lis1[i]] = (i <= p1); 
    }
    cin >> p2 >> u2;
    for (int i = 1; i <= n; ++i) {
      cin >> lis2[i];
      ord2[lis2[i]] = i;
      pin2[lis2[i]] = (i <= p2);
    }

    int ans = 0;

    {
      int leastord = n + 1;
      int lastord = 0;
      for (int i = 1; i <= n; ++i) {
        if (pin1[lis1[i]] && pin2[lis1[i]]) {
          if (ord2[lis1[i]] - 1 != lastord) {
            leastord = min(leastord, ord2[lis1[i]]);
          } else {
            ++lastord;
          }
        }
        else if (!pin1[lis1[i]] && pin2[lis1[i]]) {
          ++ans;
          leastord = min(leastord, ord2[lis1[i]]);
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (pin1[lis1[i]] && pin2[lis1[i]] && ord2[lis1[i]] >= leastord) 
          ans += 2;
      }
    }

    {
      int maxord = 0;
      int lastord = n + 1;
      for (int i = n; i >= 1; --i) {
        if (!pin1[lis1[i]] && !pin2[lis1[i]]) {
          if (ord2[lis1[i]] + 1 != lastord) {
            maxord = max(maxord, ord2[lis1[i]]);
          } else {
            --lastord;
          }
        }
        else if (pin1[lis1[i]] && !pin2[lis1[i]]) {
          ++ans;
          maxord = max(maxord, ord2[lis1[i]]);
        }
      }
      for (int i = n; i >= 1; --i) {
        if (!pin1[lis1[i]] && !pin2[lis1[i]] && ord2[lis1[i]] <= maxord) 
          ans += 2;
      }
    }

    print(ans);
    
    return 0;
}
