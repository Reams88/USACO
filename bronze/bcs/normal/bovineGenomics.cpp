#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  pair<vector<string>, vector<string>> genes;

  for(int i = 0; i < 2*n; ++i) {
    string tmp;
    cin >> tmp;
    if(i < n) genes.first.push_back(tmp);
    else genes.second.push_back(tmp);
  }

  /*
  for(int i = 0; i < n; ++i) {
    cout << genes.first[i] << endl;
  }
  for(int i = 0; i < n; ++i) {
    cout << genes.second[i] << endl;
  }*/

  int num = 0;

  for(int i = 0; i < m; ++i) {
    set<char> comb;
    set<char> less;
    set<char> spot;
    int sizes = 0;
    for(int j = 0; j < n; ++j) {
      less.insert(genes.first[j][i]);
      spot.insert(genes.second[j][i]);
    }
    sizes = less.size() + spot.size();
    comb.insert(spot.begin(), spot.end());
    comb.insert(less.begin(), less.end());
    if(sizes == comb.size()) ++num;
  }

  cout << num << endl;
    

  return 0;
}
