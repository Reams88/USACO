#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#include <print>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;

  vector<int> best(3, 0);

  for(int i = 0; i <= m/y; ++i) {
    int j = 0;
    for(; i*y + j*x <= m; ++j);
    //println("i think that {} * {} + {} * {} = {}", i, y, j-1, x, i*y + (j - 1)*x);
    int maxP = max(best[0], i*y + (j - 1)*x);
    if(maxP > best[0]) {
      best[0] = maxP;
      best[1] = (j-1);
      best[2] = i;
    }
  }
  
  cout << best[0] << endl;

  return 0;
}
