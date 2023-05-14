#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define MAXN 100000
ll dp[MAXN + 5];
set<ll> divisible[MAXN + 5];

void init() {
    for (int i = 0; i <= MAXN; ++i) {
        dp[i] = i;
    }

    for (int i = 0; i <= MAXN; ++i) {
        for (int j = 2; j <= ::sqrt(i); ++j)
            if (i % j == 0) {
                divisible[i].insert(j);
                if (i / j > 1) {
                    divisible[i].insert(i / j);
                }
            }
    }
}


int main() {
    init();
    int n;cin >> n;
    dp[1] =1 ;
    for(int i=2;i<=n;++i) {
        // a+b
        for(int a=1;a<=i/2;++a) {
            dp[i] =min(dp[i],dp[a] + dp[i-a]);
        }

        // a*b
        for(auto a : divisible[i]) {
            dp[i] = min(dp[i], dp[a] + dp[i/a]);
        }


        // a@b
        int a = i;
        int p = 1, b = 0;
        while (a != 0) {
            b = (a % 10) * p + b;
            if (a % 10 && a/10 && b) {
                a /= 10;
                dp[i] = min(dp[i], dp[a] + dp[b]);
            } else {
                a /= 10;
            }
            p = p*10;
        }
    }
    cout << dp[n];
}
