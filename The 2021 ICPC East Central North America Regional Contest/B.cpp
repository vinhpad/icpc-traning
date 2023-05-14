#include "bits/stdc++.h"
#define INF 1000000000
#define rep(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int getParent(const vector<vector<bool> >& isParent, int v){
    for(int i = 0; i < isParent.size(); i++)
        if(isParent[v][i])
            return i;
    return -1;
}

bool find(const vector<int>& v, int key){
    rep(i,0,v.size())
        if(v[i] == key)
            return true;
    return false;
}

int findAncestor(const vector<vector<bool> >& isParent, int first, int second){
    vector<int> parents;
    int p = first;
    while(p != -1){
        p = getParent(isParent, p);
        parents.push_back(p);
    }
    p = second;
    while(p !=-1){
        p = getParent(isParent, p);
        if(find(parents, p))
            return p;
    }
    return -1;
}

int getLoadAll(const vector<vector<bool> >& isParent, const vector<int>& timeAtNode,  int v){
    int total = 0;
    int p = v;
    while(p !=-1){
        total = total + timeAtNode[p];
        p = getParent(isParent, p);

    }
    return total;
}

int getLoad(const vector<vector<bool> >& isParent, const vector<int>& timeAtNode, int start, int end){
    int cur = start,totalLoad = timeAtNode[start];

    while(cur != end){
        cur = getParent(isParent, cur);
        if(cur != end)
            totalLoad = totalLoad + timeAtNode[cur];
    }
    return totalLoad;
}



int main(){
    int n,m;
    cin >> n >>m;
    vector<int> timeAtNode(n+1);
    vector<vector<bool> > isParent(n+1);

    rep(i,0,n){
        cin >> timeAtNode[i+1];
    }

    rep(i,0,n+1){
        isParent[i].resize(n+1, false);
    }

    vector<bool> otherWay(n+1, true);
    otherWay[0] = false;
    for(int i = 0; i< m; i++){
        int p, q;
        cin >> p >> q;
        isParent[q][p] = true;
        otherWay[p] = false;
    }

    int result = INF;
    rep(i,0,n+1)
        rep(j,i+1,n+1) if(otherWay[i] && otherWay[j]){
            int ancestor = findAncestor(isParent, i, j);
            int total;
            if(ancestor == -1){
                    total = getLoadAll(isParent, timeAtNode, i) + getLoadAll(isParent, timeAtNode, j);
            } else{
                total = getLoadAll(isParent, timeAtNode, ancestor)
                        + getLoad(isParent, timeAtNode, i, ancestor)
                        + getLoad(isParent, timeAtNode, j, ancestor);
            }

            result = min ( result, total);
        }

    cout << result << endl;
    return 0;
}




