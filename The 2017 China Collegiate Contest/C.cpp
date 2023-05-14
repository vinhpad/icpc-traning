#include<bits/stdc++.h>

using namespace std;

void solve(int numCase) {
    int x, y, K;
    cin >> x >> y >> K;
    int case_win = 9 * x - 11 * y;
    int case_loss = 11 * x;
    int have = 0, result = 0;

    while (x<=y) {
        if((K-result)*case_win + have >= 0 || result == K) {
            break;
        }
        have += case_loss;
        result++;
    }
    cout << "Case #" << numCase << ": " << K - result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numCase = 0;
    int numQ;
    cin >> numQ;
    while (numQ--) {
        ++numCase;
        solve(numCase);
    }
}
