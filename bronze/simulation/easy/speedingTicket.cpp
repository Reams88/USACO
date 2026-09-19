#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main() {
  
  int m, n;
  
  cin >> n >> m;
  
  vector<pair<int, int>> road(n);
  vector<pair<int, int>> bessie(m);
  
  int tmpm = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tmpm >> road[i].second;
    road[i].first = ( i != 0 ) ? road[i-1].first + tmpm : tmpm; 
  }
  tmpm = 0;
  for (int i = 0; i < m; ++i) {
    cin >> tmpm >> bessie[i].second;
    bessie[i].first = ( i != 0 ) ? bessie[i-1].first + tmpm : tmpm;
  }

  /*
  for (int i = 0; i < m; ++i) {
    cout << bessie[i].first << " " << bessie[i].second << '\n';
  }
  */
  
  int r = 0, b = 0;
  int maxover = 0;
  while (r < n && b < m) {
    maxover = max(maxover, bessie[b].second - road[r].second);
    if(road[r].first < bessie[b].first) {
      ++r;
    } else if (road[r].first > bessie[b].first) {
      ++b;
    } else {
      ++r;
      ++b;
    }
  }
  cout << maxover << '\n';
  
    
  return 0;
}
