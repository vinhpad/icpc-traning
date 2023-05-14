#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::min;
using std::max;
using std::stack;
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

struct Record
{
    int s, e;
    Long v;

    Record() : v(-1) {}

    Record(int s, int e, Long h) 
    : s(s), e(e), v(Long(e - s + 1) * h) {}
};

bool operator < (const Record& a, const Record& b)
{
    if (a.v != b.v)
        return a.v < b.v;
    if (a.s != b.s) return a.s > b.s;
    return a.e > b.e;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    Record ans = {};
    ans.v = -1;

    vector<int> left(n + 1), right(n + 1);

    stack<int> stk;
    for (int i = 1; i <= n; ++i) {
      while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
      left[i] = stk.empty() ? 1 : stk.top() + 1;
      stk.push(i);
    }
    stk = stack<int>();

    for (int i = n; i >= 1; --i) {
      while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
      right[i] = stk.empty() ? n : stk.top() - 1;
      stk.push(i);
    }

    for (int i = 1; i <= n; ++i) {
      ans = max(ans, Record(left[i], right[i], a[i]));
    }

    print(ans.s,' ',ans.e,' ',ans.v);

    return 0;
}
