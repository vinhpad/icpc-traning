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

struct BigInt : vector<char>
{
    BigInt(unsigned long long x = 0)
    {
        while (x) {
          push_back(x % 10);
          x /= 10;
        }
    }

    friend std::ostream& operator << (std::ostream &os, const BigInt &x) 
    {
        for (int i = x.size(); i --> 0;) {
          char c = x[i] + '0';
          os << c;
        }
        return os;
    }

    friend BigInt operator * (BigInt l, BigInt r)
    {
        BigInt result = 0;
        result.resize(l.size() + r.size());
        for (int i = 0; i < l.size(); ++i) {
          int tmp = 0;
          for (int j = 0; j < r.size(); ++j) {
            tmp += result[i+j] + l[i] * r[j];
            result[i+j] = tmp % 10;
            tmp /= 10;
          }
          result[i+r.size()] = tmp;
        }
        
        if (!result.empty() && !result.back()) result.pop_back();
        return result;
    }
    friend BigInt operator + (BigInt l, BigInt r)
    {
        if (l.size() < r.size()) l.swap(r);
        BigInt result;
        result.resize(l.size() + 1);
        int tmp = 0;
        for (int i = 0; i < l.size(); ++i) {
          result[i] = tmp + l[i] + (i < r.size() ? r[i] : 0);
          if (tmp = (result[i] >= 10)) result[i] -= 10; 
        }
        if (tmp) result.back() = 1;
        else result.pop_back();
        return result;
    }
    friend BigInt operator - (BigInt l, BigInt r)
    {
        BigInt result;
        result.resize(l.size());
        int tmp = 0;
        for (int i = 0; i < l.size(); ++i) {
          result[i] = l[i] - (i < r.size() ? r[i] : 0) - tmp;
          if (tmp = (result[i] < 0)) result[i] += 10; 
        }
        while (!result.empty() && result.back() == 0) result.pop_back();
        return result;
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

    /// 4n-3, 2n+1 -> 2n-4->n-2 -> (n-2)(n-1)/2
    /// (4n-3)^2-2(n-1)(n-2) + 12n +4

    int t;
    cin >> t;
    const int results[] = {1, 9, 41, 109};
    for (int i = 1; i <= t; ++i) {
      BigInt n;
      int n_;
      cin >> n_;
      n = n_;
      BigInt result;
      if (n_ < 4) result = results[n_];
      else result = 14*n*n+5-6*n;
      cout << "Case #" << i << ": " << result;
      cout << '\n';
    }

    return 0;
}
