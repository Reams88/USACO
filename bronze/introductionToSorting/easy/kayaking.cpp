#include <climits>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("test", "r", stdin);
  //freopen("out", "w", stdout);

  int n;
  cin >> n;

  vector<int> weights(2*n);
  for(int i = 0; i < 2*n; ++i) {
    cin >> weights[i];
  }

  for(int i = 0; i < 2*n-1; ++i) {
    bool done = true;
    for(int j = 0; j < 2*n-1-i; ++j) {
      if(weights[j] > weights[j+1]) swap(weights[j], weights[j+1]);
      done = false;
    }
    if(done) break;
  }

  //for(int num : weights) cout << num << ' ';
  //cout << endl;

  int mindiff = INT_MAX;
  for(int i = 0; i < 2*n-1; ++i) {
    for(int j = i+1; j < 2*n; ++j) {
      int diff = 0;
      vector<int> temp;
      for (int k = 0; k < 2 * n; ++k) {
        if (k != i && k != j) {
          temp.push_back(weights[k]);
        }
      }
      for (size_t k = 0; k < temp.size(); k += 2) {
        diff += temp[k + 1] - temp[k];
      }

      mindiff = min(mindiff, diff);
    }
  }

  cout << mindiff << endl;

  return 0;
}
