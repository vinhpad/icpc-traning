#include "bits/stdc++.h"

using namespace std;
string s,t;
int n;
vector<int> a;
void process(){
    cin >> n;
    cin >> s >> t;
    a.clear();
    for (int i=0;i<n;++i) {
        a.push_back((s[i]-'0') xor (t[i]-'0'));
    }

    int count_seq = 0;
    int count_one = 0;
    for(int i=0;i<n;++i) {
        if(a[i]) {
            count_one ++ ;
            if(!i || !a[i-1]) {
                count_seq++;
            }
        }
    }

    if(count_seq > 2) {
        cout << 0 << endl;
    } else {
        long long count_zero_left = 0;
        long long count_zero_right = 0;
        for(int i=0;i<n;++i) {
            count_zero_left += (a[i]==0 ? 1 : 0);
            if(a[i]) break;
        }

        for(int i=n-1;i>=0;--i) {
            count_zero_right += (a[i]==0 ? 1 : 0);
            if(a[i]) break;
        }

        if(count_seq == 1) {
            cout << (count_one-1)*2 + count_zero_left*2 + count_zero_right*2<< endl;
        } else {
            if(count_seq == 2) {
                cout << 6 << endl;
            }
            else {
                cout <<(long long)((count_zero_left*1ll)*(count_zero_left*1ll+1ll)/2ll) << endl;
            }
        }
    }
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
