#include "bits/stdc++.h"
using namespace std;
int n,k;
vector<int> arr;
map<int,vector<int>> temp;
map<int,vector<int>> map_index;
int main() {
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        int x; cin >> x;
        arr.push_back(x);
        temp[x].push_back(i);
    }

    for(auto [val,index_list] : temp) {
        for(int index : index_list) {
            map_index[index_list.size()].push_back(index);
        }
    }

    k--;
    while(k--) {

        temp.clear();
        for(auto [val,index_list] : map_index) {
            if(index_list.size() == val) continue;
            //cout << val << " " << index_list.size() << endl;
            for_each(begin(index_list),end(index_list),[&](int index){
                temp[index_list.size()].push_back(index);
            });
            map_index[val].clear();
        }


        for(auto [val,index_list] : temp) {
            for_each(index_list.begin(), index_list.end(),[&](int index){
                map_index[val].push_back(index);
            });
        }

        if(temp.size()==0) break;
    }

    for(auto [val,index_list] : map_index) {
        for_each(index_list.begin(),index_list.end(),[&](int index){
            arr[index] = val;
        });
    }

    for(int i=0;i<n;++i) {
        cout << arr[i] << ' ';
    }

}
