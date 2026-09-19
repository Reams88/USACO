#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <print>

using namespace std;
using ull = unsigned long long;



int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int, int>> coords(n, {0, 0});
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < n; ++j) {
      (i == 0) ? cin >> coords[j].first : cin >> coords[j].second;
    }
  }

  int maxDist = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      int dist = pow(coords[j].first - coords[i].first, 2) + pow(coords[j].second - coords[i].second, 2);
      //println("from ({},{}) to ({},{}) is {}", coords[i].first, coords[i].second, coords[j].first, coords[j].second, dist);
      maxDist = max(maxDist, dist);
    }
  }

  cout << maxDist << endl;
  
  
  return 0;
}
