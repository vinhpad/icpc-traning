#include "bits/stdc++.h"

using namespace std;

/*
void process() {
    int n; cin >> n;
    string s,t;

    //vector<int> s(n,0);
    //vector<int> t(n,0);

    for(int i=0;i<n ; ++i) {
        cin >> s[i];
    }

    for(int i=0;i<n;++i) {
        cin >> t[i];
    }

    auto solve = [&s,&t,&n](){
        int count_seg = 0;
        vector<int> a(n,0);
        for(int i=0;i<n;++i) {
            a[i] = (s[i]-'0') xor (t[i]-'0');
        }

        for(int i=0;i<n;++i) {
            if((a[i]&&!i) || (a[i]&&!a[i-1])) {
                count_seg ++ ;
            }

            if(a[i])
            cout << a[i];
        }cout << endl;

        if(count_seg > 2) {
            return 0;
        }

    };

    int result = solve();
    //cout << result << endl;
}
*/

int f(int x) {
    int sum_dig = 0;

    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 0;
    if(x == 3) return 0;
    if(x == 4) return 1;
    if(x == 5) return 0;
    if(x == 6) return 1;
    if(x == 7) return 0;
    if(x == 8) return 2;
    if(x == 9) return 1;

    while(x) {
        sum_dig += (f(x%10));
        x /= 10;
    }
    return sum_dig;
}

int g(int k,int x) {
    if(k==0) {
        return x;
    }
    for(int i=1;i<=k;++i) {
        x = f(x);
        if(x==0) {
            if((k-i)%2) return 1;
            else return 0;
        }
    }
    return x;
}

void process() {
    long long x, k;
    cin >> x >> k;
    cout << g(k,x) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numQuery;
    cin >> numQuery;
    while (numQuery--) {
        process();
    }
}
