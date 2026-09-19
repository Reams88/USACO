#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdio>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n;
  cin >> n;
  
  vector<tuple<int, int, int>> list(n);

  for(int i = 0; i < n; ++i) {
    cin >> get<0>(list[i]) >> get<1>(list[i]) >> get<2>(list[i]);
  }

  vector<int> a;
  a.resize(1001); 

  int maxb = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = get<0>(list[i]); j <= get<1>(list[i]); ++j) {
      a[j] += get<2>(list[i]);
      maxb = max(maxb, a[j]);
    } 
  }

  cout << maxb << '\n';  

  return 0;
}
