#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
//#include <print>
#include <set>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n;
  cin >> k >> n;

  vector<vector<pair<int, int>>> scores(n);
  for(int i = 0; i < k; ++i) {
    for(int j = 1; j < n+1; ++j) {
      int tmp;
      cin >> tmp;
      scores[tmp - 1].push_back(make_pair(tmp, j));
    }
  }

  /*for(const auto& score : scores) {
    for(const auto& cows : score) {
      println("({},{})", cows.first, cows.second);
    }
  }*/

  int num = 0;

  //cout << endl;

  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      bool greater = false, lesser = false;
      for(int l = 0; l < k; ++l) {
        if(scores[i][l].second >= scores[j][l].second) greater = true;
        else lesser = true;
        //println("({},{}) and ({},{}). greater = {}, lesser = {}", scores[i][l].first, scores[i][l].second, scores[j][l].first, scores[j][l].second, greater, lesser);
      }
      if(greater ^ lesser) ++num;
    }
  }

  cout << num << endl; 

  return 0;
}
