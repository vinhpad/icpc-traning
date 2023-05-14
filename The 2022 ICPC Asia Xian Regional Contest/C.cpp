#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long a,b,c;
  cin >> a >> b >> c;

  long long numRanran = 1;
  long long result = b*c;
  for(long long i=1;i<=trunc(log2(c))+1;++i) {
    numRanran*=2;
    numRanran= min(numRanran,c);
    long long prevTime = i*a;
    long long nextTime = (c/numRanran)*b;
    if(c%numRanran !=0) nextTime += b;
    result = min(result,prevTime + nextTime);
    //cout << numRanran << " " <<  prevTime << " " << nextTime << endl;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int numQ;cin >> numQ;
  while(numQ--) {
    solve();
  }
}