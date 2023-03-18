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
 
static const int query = 0;
static const int open = 1;
static const int close = -1;
struct Event
{
    int type;
    int pos;
    friend bool operator < (Event l, Event r)
    {
        if (l.pos != r.pos) return l.pos < r.pos;
        return l.type > r.type;
    }
};
 
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
    vector<int> a(n);
    int min = 1000000000;
    for (int &x : a) {
      cin >> x;
      min = std::min(min, x);
    }
    bool maximized = true;
    for (int x : a) {
      if (x == min || x / 2 >= min) {}
      else {
        maximized = false;
        break;
      }
    }
    if (maximized) print(min);
    else print(min / 2);
    // vector<Event> events;
    // int mx = 1000000000;
    // int ans = 1;
    // for (int i = 0; i < n; ++i) {
    //   cin >> a[i];
    //   events.push_back({open, 1});
    //   events.push_back({close, (a[i] - 1) / 2});
    //   events.push_back({open, a[i]});
    //   events.push_back({close, a[i]});
    //   events.push_back({query, a[i]});
    //   mx = min(mx, (a[i] - 1) / 2);
    // }
 
    // events.push_back({query, mx});
 
    // std::sort(events.begin(), events.end());
 
    // int count = 0;
    // for (Event e : events) {
    //   if (e.type == open) ++count;
    //   else if (e.type == close) --count;
    //   else if (count == n) ans = e.pos;
    // }
 
    // print(ans);
 
    return 0;
}


