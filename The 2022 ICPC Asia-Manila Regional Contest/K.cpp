#include <map>
#include <set>
#include <array>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
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

using bools = std::array<bool, 26>;
const string FIRST_ROW = "QWERTYUIOP";
const string SECOND_ROW = "ASDFGHJKL";
const string THIRD_ROW = "ZXCVBNM";

bools getPressed(string row1, string row2, string row3)
{
    bools res{};
    res.fill(true);
    for (char c : row1)
      if ('A' <= c && c <= 'Z') res[c - 'A'] = false;
    for (char c : row2)
      if ('A' <= c && c <= 'Z') res[c - 'A'] = false;
    for (char c : row3)
      if ('A' <= c && c <= 'Z') res[c - 'A'] = false;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    string row1, row2, row3;
    cin >> row1 >> row2 >> row3;
    bools pressed = getPressed(row1, row2, row3);
    int nPressed = std::accumulate(pressed.begin(), pressed.end(), 0);
    int q;
    cin >> q;
    while (q--) {
      string s;
      cin >> s;
      bools req = pressed;
      int nReq = nPressed;
      bool possible = true;
      for (char c : s) {
        if (c < 'A' || c > 'Z') {
          possible = false;
          break;
        }
        if (pressed[c - 'A'] == false) {
          possible = false;
          break;
        }
        if (req[c - 'A'] == true) {
          --nReq;
          req[c - 'A'] = false;
        }
      }
      if (possible && nReq == 0)
        println("POSSIBLE");
      else
        println("IMPOSSIBLE");
    }

    return 0;
}
