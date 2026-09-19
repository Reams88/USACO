#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("cbarn.in", "r", stdin);
  //freopen("cbarn.out", "w", stdout);

  ull n;
  cin >> n;

  vector<ull> rooms(n);

  pair<ull, ull> lowest = {18446744073709551610, 0}; 

  for (int i = 0; i < n; ++i) {
    cin >> rooms[i];
  }

  ull mincurr = 0, currm = 1, distance = 0, adjindx = 0;
  for(ull i = 0; i < n; ++i) {
    currm = 1;
    for(ull j = i+1; j < n + i; ++j) {
      (j >= n) ? adjindx = j - n: adjindx = j;
      distance = distance + rooms[adjindx] * (j - i);
    }
    
    mincurr = min(distance, lowest.first);
    if(mincurr != lowest.first) {
      lowest.first = mincurr;
      lowest.second = i;
    }
    distance = 0;
  }

  cout << lowest.first << '\n';

  return 0;
}
