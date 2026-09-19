#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <map>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<string, string>> cards(n, {" "," "});
  
  for(int i = 0; i < n; ++i) {
    cin >> cards[i].first >> cards[i].second;
  }

  vector<int> alphabet(26, 0);
  
  
  for(const auto& elem : cards) {
    vector<int> mask1(26, 0);
    vector<int> mask2(26, 0);
    for(char letter : elem.first) {
      ++mask1[letter - 97]; 
    }
    for(char letter : elem.second) {
      ++mask2[letter - 97];
    }
    for(int i = 0; i < 26; ++i) {
      alphabet[i] += max(mask1[i], mask2[i]);
    }
  }

  for(int num : alphabet) cout << num << '\n';

  return 0;
}
