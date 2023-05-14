#include "bits/stdc++.h";
using namespace std;
int x;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> x;
    if(x<=-3) {
        cout << -(x+4)*(x+4) + 8;
    }
    else {
        if(x<=2) {
            cout << -2*x + 1;
        } else {
            cout << x*x*x + -14*x + 17;
        }
    }
}
