#include "bits/stdc++.h"

using namespace std;
int N, H, W;
char to_work, go_home;

void process() {
    cin >> N >> H >> W;

    while (N--) {
        cin >> to_work >> go_home;

        if ((to_work == 'Y' || !W) && H) {
            H--;W++;
            cout << 'Y' << ' ';
        } else {
            cout << 'N' << ' ';
        }

        if ((go_home == 'Y' || !H) && W) {
            W--;H++;
            cout << 'Y' << ' ';
        } else {
            cout << 'N' << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    process();
}
