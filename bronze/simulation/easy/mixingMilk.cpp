#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ull = unsigned long long;

int main() {
  vector<pair<ull, ull>> milkTable(3);
  
  for (int i = 0; i < 3; ++i) {
    cin >> milkTable[i].first;
    cin >> milkTable[i].second;
  }
  
  int curr = 0, next = 0;
  for (int n = 0; n < 100; ++n) {
    (curr != 2) ? next = curr + 1 : next = 0;
    milkTable[next].second += milkTable[curr].second;
    if(milkTable[next].second > milkTable[next].first) {
      milkTable[curr].second = milkTable[next].second - milkTable[next].first;
      milkTable[next].second = milkTable[next].first;
    } else {
      milkTable[curr].second = 0;
    }
    (curr == 2) ? curr = 0 : ++curr;
  }
  
  for (int i = 0; i < 3; ++i) {
    cout << milkTable[i].second << '\n';
  }
  
  return 0;
}
