#include "bits/stdc++.h"

using namespace std;

int N,M;
int a[100005];
void process(){
    cin >> N >> M;
    for(int i=1;i<=N;++i) cin >> a[i];
    int t1 = M,t2 = 0;
    for(int i = 1;i<=N;i++) if(a[i] <= 0) t2++;
    if(t2>t1) puts("Impossible");
    else if(t1 == 0){
        int mi = 1e9+10;
        for(int i = 1;i<=N;i++) mi = min(mi,a[i]);
        printf("%d\n",mi-1);
    }else{
        if(t1 == N) puts("Richman");
        else{
            t1 -= t2;
            long long ans = 0,ok = 1;
            for(int i =1;i<=N;i++){
                if(t1>0){
                    if(a[i] != 0) {
                        ans += a[i];
                        t1--;
                    }
                }else{
                    int mi = 1e9+10;
                    for(int j = i;j<=N;j++){
                        if(a[j] != 0) mi = min(mi,a[j]);
                    }
                    ans += mi-1;
                    break;
                }
            }
            printf("%lld\n",ans);
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
