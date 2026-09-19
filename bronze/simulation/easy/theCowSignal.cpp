#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ull = unsigned long long;

int main() {
  
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  
  vector<string> sign(m, string(n, ' '));
  vector<string> signb(m*k, string(n*k, ' '));
  
  for (int i = 0; i < m; ++i) {
    cin >> sign[i];
  }

  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int l = 0; l < k; ++l) {
        for(int p = 0; p < k; ++p) {
          signb[i * k + l][j * k + p] = sign[i][j];
        }
      }
    }
  }
  

  for (int i = 0; i < m*k; ++i) {
    for(int j = 0; j < n*k; ++j) {
      cout << signb[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
