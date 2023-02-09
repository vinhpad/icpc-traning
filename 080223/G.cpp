#include <bits/stdc++.h>

using namespace std;
const int NUM_CHAR = 'z' - 'a' + 1;
const int MAX_NODE = 200000;

struct Trie {

  struct Node {
    int child[NUM_CHAR];
  }nodes[MAX_NODE];
  int countNode = 0;

  void init() {
    for(int i=0;i<MAX_NODE;++i) {
      for(int c=0;c<'z'-'a';++c) {
        nodes[i].child[c] = 0;
      }
    }
  }

  void addWord(string str) {
    int root = 0;
    for (auto c: str) {
      if (!nodes[root].child[c-'a']) {
        nodes[root].child[c-'a'] = ++countNode;
        root = countNode;
      } else root = nodes[root].child[c-'a'];
    }
  }

  bool findWord(string str) {
    int root = 0;
    for(auto c : str) {
      if (!nodes[root].child[c-'a']) {
        return false;
      }
      root = nodes[root].child[c-'a'];
    }
    return true;
  }
}trie;

int numStr;
string strList[100005];
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  if(fopen(".inp","r")){
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
  }
  trie.init();
  cin >> numStr;
  for(int i=0;i<numStr;++i) {
    //string str;cin >> str;
    cin >> strList[i];
  }

  sort(strList, strList+numStr,
       [](string &f,string &s){
                return f.size()<s.size();}
       );

  int result = 0;
  for(int pos =0 ;pos<numStr;++pos) {
    string str = strList[pos];
    if(str.size()==1) {
      trie.addWord(str);
      result = 1;
    } else {
      string rmBeg = "";
      for(int i=1;i<str.size();++i) rmBeg.push_back(str[i]);
      string rmEnd = "";
      for(int i=0;i<str.size()-1;++i) rmEnd.push_back(str[i]);

      if(trie.findWord(rmBeg)&&trie.findWord(rmEnd)) {
        trie.addWord(str);
        result = str.size();
      }
    }
  }

  cout << result;
}
