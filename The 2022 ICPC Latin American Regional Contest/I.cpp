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

constexpr int RMAX = 100;
constexpr int CMAX = 100;
constexpr int VMAX = 10000;

struct Point { int x, y; };

int r, c;
int a[RMAX][CMAX];
int check[VMAX + 1];
Point p[VMAX + 1];



int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
        cin >> a[i][j];
        p[a[i][j]] = {i, j};
    }

    int ans = -1;
    int rc = r * c;
    for (int i = 1; i <= rc; ++i) {
      memset(check + 1, 0, rc * sizeof(int));
      int dishes = 0;
      int counter = 0;
      check[i] = 1;
      while (true) {
        for(++counter; counter <= rc && !check[counter]; ++counter) {
        }
        if (counter > rc) break;
        ++dishes;
        Point next = p[counter];
        if (next.x - 1 >= 0) check[a[next.x - 1][next.y]] = 1;
        if (next.y + 1 < c) check[a[next.x][next.y + 1]] = 1;
        if (next.y - 1 >= 0) check[a[next.x][next.y - 1]] = 1;
        if (next.x + 1 < r) check[a[next.x + 1][next.y]] = 1;
      }
      ans = max(ans, dishes);
    }

    print(ans);

    return 0;
}
