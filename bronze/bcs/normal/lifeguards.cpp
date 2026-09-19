#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);


  int n = 0;
  cin >> n;


  vector<pair<int, int>> coords(n, {0,0});
  for(int i = 0; i < n; ++i) {
    cin >> coords[i].first >> coords[i].second;
  }

  
  int best = INT_MAX;
  for(int k = 0; k < n; ++k) {  
    vector<int> heatmap(999, 0);
    for(int i = 0; i < n; ++i) {
      //cout << '\n' << coords[i].first-1 << ' ' << coords[i].second << endl;
      for(int j = coords[i].first-1; j < coords[i].second-1; ++j) {
        if(i != k) ++heatmap[j];
        else continue;
        //cout << j << ' ' << coords[i].second << endl;
      }
    }
    int size = 0;
    //bool is = false;
    for(int el : heatmap) {
      (el == 0) ? ++size : ' ';
      //if(el > 1) is = true;
    }

    //for(int el : heatmap) cout << el << ' ';
    //cout << '\n' << 999 - size << '\n';
    /*
    int allN = 0;
    for(int u = 0; u < heatmap.size(); ++u) allN += heatmap[u];
    */
    int currmin = min(best, size);
    if(currmin < best) {
      best = currmin;
    }
  }

  cout << 999 - best << endl;

  return 0;
}
