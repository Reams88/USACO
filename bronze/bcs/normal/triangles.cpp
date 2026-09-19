#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
//#include <print>
#include <cmath>

using namespace std;
using ull = long long;

int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<pair<ull, ull>> coords(n, {0,0});
  for(int i = 0; i < n; ++i) cin >> coords[i].first >> coords[i].second;

  sort(coords.begin(), coords.end(), [](const auto& a, const auto& b){
      return a.second < b.second;
    });

  vector<vector<ull>> allX;
  
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      if(coords[i].second != coords[j].second) {
        continue;
      }
      allX.push_back({coords[i].first, coords[i].second, coords[j].first, coords[j].second, abs(coords[i].first - coords[j].first)});
    }
  }

  sort(coords.begin(), coords.end(), [](const auto& a, const auto& b){
      return a.first < b.first;
    });

  //for(const auto& elem : coords) println("({},{})", elem.first, elem.second);

  vector<vector<ull>> allY;
  
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      if(coords[i].first != coords[j].first) {
        //println("({}{})({}{}) {}", coords[i].first, coords[i].second, coords[j].first, coords[j].second, abs(coords[i].second - coords[j].second));
        continue;
      }
      //println("({}{})({}{}) {}", coords[i].first, coords[i].second, coords[j].first, coords[j].second, abs(coords[i].second - coords[j].second));
      allY.push_back({coords[i].first, coords[i].second, coords[j].first, coords[j].second, abs(coords[i].second - coords[j].second)});
    }
  }

  /*
  cout << endl;

  for(const auto& vec : allX) println("({},{}) and ({},{}) dist = {}", vec[0], vec[1], vec[2], vec[3], vec[4]);

  cout << endl;
  
  for(const auto& vec : allY) println("({},{}) and ({},{}) dist = {}", vec[0], vec[1], vec[2], vec[3], vec[4]);

  cout << endl;
  */

  //vector<ull> biggest;
  ull maxLen = 0, maxCurr = 0;

  for(int i = 0; i < allX.size(); ++i) {
    for(int j = 0; j < allY.size(); ++j) {
      if(!((allY[j][0] == allX[i][0] && allY[j][1] == allX[i][1]) || (allY[j][0] == allX[i][2] && allY[j][1] == allX[i][3]) || (allY[j][2] == allX[i][0] && allY[j][3] == allX[i][1]) ||(allY[j][2] == allX[i][2] && allY[j][3] == allX[i][3]))) continue;
      maxCurr = allY[j][4]*allX[i][4];
      //println("({},{}) ({},{}) and ({},{}) ({},{}) = {}", allX[i][0], allX[i][1],allX[i][2],allX[i][3],allY[j][0],allY[j][1],allY[j][2],allY[j][3], maxCurr);
      maxLen = max(maxCurr, maxLen);
    }
  }

  cout << maxLen << endl;


  //for(const auto& elem : coords) println("({},{})", elem.first, elem.second);

  //sort(coords.begin(), coords.end(), &pair<int,int>::first);

  //for(const auto& elem : coords) println("({},{})", elem.first, elem.second);
  
  return 0;
}
