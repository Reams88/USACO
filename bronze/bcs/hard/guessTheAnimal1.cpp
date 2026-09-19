#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("guess.in", "r", stdin);
  //freopen("guess.out", "w", stdout);

  int n;
  cin >> n;

  vector<set<string>> traits(n);
  for(int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    int num;
    cin >> num;
    for(int j = 0; j < num; ++j) {
      string str;
      cin >> str;
      traits[i].insert(str);
    }
  }

  int maxOverlap = 0;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == j) continue;
      set<string> overlap;
      overlap.insert(traits[i].begin(), traits[i].end());
      overlap.insert(traits[j].begin(), traits[j].end());
      int combLen = traits[i].size() + traits[j].size() - overlap.size();
      maxOverlap = max(combLen, maxOverlap);
    }
  }

  cout << maxOverlap + 1<< endl;

  return 0;
}
