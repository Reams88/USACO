#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <print>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  

  int n, k;
  cin >> n >> k;

  vector<int> diamonds(n);
  for(int i = 0; i < n; ++i) {
    cin >> diamonds[i];
  }
  
  sort(diamonds.begin(), diamonds.end());

  int maxAm = 0;
  for(int i = 0; i < n; ++i) {
    int maxCurr = 1;
    for(int j = i+1; j < n; ++j) {
      if(abs(diamonds[i] - diamonds[j]) <= k) {
        ++maxCurr;
        //println("i chose {} for {}", diamonds[j], diamonds[i]);
      }
    }
    maxAm = max(maxAm, maxCurr);
  }

  cout << maxAm << endl;

  return 0;
}
