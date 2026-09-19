#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<char, int>> path(n, {' ', 0});

  for(int i = 0; i < n; ++i) {
    cin >> path[i].first >> path[i].second;
  }

  vector<pair<int, int>> coords = {{0, 0}};
  vector<int> time = {0};
  int lowestX = INT_MAX;

  for(const auto& turn : path) {
    //cout << turn.first << ' ' << turn.second << endl;
    for(int i = 0; i < turn.second; ++i) {
      int x = 0, y = 0;
      switch(turn.first) {
        case 'W':
          x = coords.back().first + 1;
          y = coords.back().second;
          break;
        case 'E':
          x = coords.back().first - 1;
          y = coords.back().second;
          break;
        case 'N':
          x = coords.back().first;
          y = coords.back().second + 1;
          break;
        case 'S':
          x = coords.back().first;
          y = coords.back().second - 1;
          break;
      }
      time.push_back(time.back() + 1);
      //cout << time.back() << " (" << x << ' ' << y << ")" << endl;
      auto itCurr = find(coords.rbegin(), coords.rend(), make_pair(x, y));
      if(itCurr != coords.rend()) {
        int indx = coords.size() - 1 - distance(coords.rbegin(), itCurr);
        lowestX = min(lowestX, time.back() - time[indx]);
        //cout << "found!! heres time now and time then " << time.back() << " = " << time[indx] << "im dumb and think that its " << ((itCurr != coords.end()) ? "True" : "False") << endl; 
      }
      coords.push_back({x,y});
    }
    //cout << endl;
  }
  
  //for(int i = 0; i < distance(coords.begin(), coords.end()); ++i) {
    //cout << coords[i].first << " " << coords[i].second << " | t = " << time[i] << endl;
  //}

  cout << ((lowestX == INT_MAX) ? -1 : lowestX) << endl;

  return 0;
}
