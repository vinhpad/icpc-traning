#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, sLen;
char s[MAXN + 10];

int A[MAXN + 10], B[MAXN + 10], f[10][100];

int gao(int x, int &now) {
    if (now > sLen) return -1;
    if (s[now] == '0') {
        now++;
        return 0;
    }

    int t = s[now] - '0';
    if (f[x][t] > 0) {
        now++;
        return f[x][t];
    }

    t = t * 10 + (s[now + 1] - '0');
    if (now < sLen && f[x][t] > 0) {
        now += 2;
        return f[x][t];
    }

    return -1;
}
bool check(int X) {
    A[1] = X;

    int now = 1;
    for (int i = 1; i <= m; i++) {
        B[i] = gao(X, now);
        if (B[i] < 0) return false;
    }

    if (B[1] == 0) return false;

    for (int i = 2; i <= n; i++) {
        A[i] = gao(B[1], now);
        if (A[i] < 0) return false;
 
        for (int j = 2; j <= m; j++) {
            int t = A[i] * B[j];
            int l = t >= 10 ? 2 : 1;
            for (int k = l - 1; k >= 0; k--) {
                if (now + k > sLen || s[now + k] - '0' != t % 10) return false;
                t /= 10;
            }
            now += l;
        }
    }

    return now == sLen + 1;
}

void solve() {
    scanf("%d%d%s", &n, &m, s + 1);
    sLen = strlen(s + 1);

    for (int i = 1; i <= 9; i++) if (check(i)) {
        for (int j = 1; j <= n; j++) printf("%d", A[j]);
        printf(" ");
        for (int j = 1; j <= m; j++) printf("%d", B[j]);
        printf("\n");
        return;
    }
    printf("Impossible\n");
}

int main() {

    for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) f[i][i * j] = j;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

