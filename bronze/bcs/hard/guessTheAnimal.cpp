#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
//#include <print>
#include <cmath>
#include <string>
#include <map>

using namespace std;
using ull = long long;

int main() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  
  int n;
  cin >> n;

  map<string, int> frqMap;

  vector<vector<string>> guesses(n);
  for(int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    guesses[i].push_back(name);
    string num;
    cin >> num;
    guesses[i].push_back(num);
    for(int j = 0; j < stoi(num); ++j) {
      cin >> name;
      guesses[i].push_back(name);
      ++frqMap[name];
    }
  }
  
  /*
  for(const auto& par : frqMap) {
    cout << par.first << ' ' << par.second << endl;
  }
  cout << endl;
  */
  
  sort(guesses.begin(), guesses.end(), [](const auto& a, const auto& b) {
      return a.size() < b.size();
  });
  
  int maxYes = 0;
  for(const auto& vec : guesses) {
    int currMax = 0;
    for(int i = 2; i < vec.size(); ++i) {
      //cout << vec[i] << ' ' << frqMap[vec[i]] << endl;
      if(frqMap[vec[i]] - 1 != 0) {
        ++currMax;
      }
    }
    //cout << endl;
    maxYes = max(currMax, maxYes);
  }
  
  cout << maxYes + 1 << endl;
  
  /*
  for(const auto& elem : guesses) {
    for(const auto& str : elem) {
      cout << str << ' ';
    }
    cout << endl;
  }
  */
  
  
  
  return 0;
}
