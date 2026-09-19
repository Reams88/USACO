#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  int t;
  cin >> t;

  for(int times = 0; times < t; ++times) {
    int n, k;
    cin >> n >> k;

    if(k < n || k >= 2*n) {
      cout << -1 << "\n";
      continue;
    }

    int amount = 2*n - k;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int seq = 1;

    for(int i = 0; i < amount; ++i) {
      matrix[i][i] = seq;
      ++seq;
    }

    for(int i = amount; i < n; ++i) {
      matrix[i][0] = seq;
      ++seq;
    }

    for(int i = amount; i < n; ++i) {
      matrix[0][i] = seq;
      ++seq;
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(matrix[i][j] == 0) {
          matrix[i][j] = seq;
          ++seq;
        }
      }
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        cout << matrix[i][j] << (j == n - 1 ? "" : " ");
      }
      cout << "\n";
    }
  }

  return 0;
}
