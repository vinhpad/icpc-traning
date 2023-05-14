#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using std::cin;
using std::cout;
using std::min;
using std::max;
using std::string;
using std::vector;

using Long = long long;

struct Point { int x, y; };

string reversed(string vec)
{
    std::reverse(vec.begin(), vec.end());
    return vec;
}

bool isFit(const string &bolt, int rotate, const string &row)
{
    for (int i = 0; i < bolt.size(); ++i) {
      int rotated = i + rotate;
      if (rotated >= bolt.size()) rotated -= bolt.size();
      if (bolt[i] == '1' && row[rotated] == '1') return false;
    }
    return true;
}

bool check(string bolt, vector<string> maze)
{
    int r = maze.size(), c = maze[0].size();
    vector<vector<int>> simplified(r, vector<int>(c));
    auto mark = simplified; // copy the structure
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        simplified[i][j] = isFit(bolt, j, maze[i]);
      }
    }

    std::queue<Point> q;
    for (int i = 0; i < c; ++i) {
      if (simplified[0][i]) {
        q.push({0, i});
        mark[0][i] = true;
      }
    }
    while (!q.empty()) {
      Point next = q.front();
      q.pop();
      if (next.x == r - 1) return true;
      if (next.x > 0 && simplified[next.x - 1][next.y] && !mark[next.x - 1][next.y]) {
        q.push({next.x - 1, next.y});
        mark[next.x - 1][next.y] = true;
      }
      if (simplified[next.x + 1][next.y] && !mark[next.x + 1][next.y]) {
        q.push({next.x + 1, next.y});
        mark[next.x + 1][next.y] = true;
      }
      int left = next.y - 1;
      if (left < 0) left += c;
      if (simplified[next.x][left] && !mark[next.x][left]) {
        q.push({next.x, left});
        mark[next.x][left] = true;
      }
      int right = next.y + 1;
      if (right >= c) right -= c;
      if (simplified[next.x][right] && !mark[next.x][right]) {
        q.push({next.x, right});
        mark[next.x][right] = true;
      }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef TASK
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif

    int r, c;
    cin >> r >> c;
    string bolt;
    vector<string> maze(r);
    cin >> bolt;
    for (int i = 0; i < r; ++i) {
      cin >> maze[i];
    }
    if (check(bolt, maze) || check(reversed(bolt), maze)) cout << "Y";
    else cout << "N";
    return 0;
}
