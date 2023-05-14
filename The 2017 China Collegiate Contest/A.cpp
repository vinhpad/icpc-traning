#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

using std::cin;
using std::cout;
using std::min;
using std::max;
using std::string;
using std::vector;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
      int n;
      cin >> n;
      cout << "Case #" << i << ": " << std::setprecision(10) << std::fixed << (double) (n - 1) << '\n';
    }


    return 0;
}
