#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int t;
  cin >> t;

  for(int times = 0; times < t; ++times) {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> cards(n);

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        int num;
        cin >> num;
        cards[i].push_back(num);
      }
    }

    int totalSum = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = i+1; j < n; ++j) {
        int partialSum = 0;
        for(int k = 0; k < m; ++k) {
          partialSum += abs(cards[i][k] - cards[j][k]);
          //cout << cards[i][k] << " - " << cards[j][k] << endl;
        }
        totalSum += partialSum;
      }
    }

    cout << totalSum << endl;
  
  }

  return 0;
}
