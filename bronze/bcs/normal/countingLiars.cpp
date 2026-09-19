#include <iostream>
#include <cstdio>
#include <vector>
#include <pair>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<pair<char, ull>> cows(n, {'A', 0});
  for(int i = 0; i < n; ++i) {
    cin >> cows[i].second >> cows[i].first;
  }

  sort(cows.begin(), cows.end());
  
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(j == i) continue;
      if()
    }
  }


  return 0;
}
