#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main() {
  int swaps;
  cin >> swaps;
    
  vector<int> points = {0, 0, 0};
  vector<int> shells = {1, 2, 3};

  int shell1, shell2, guess;
  for (int i = 0; i < swaps; ++i){
    cin >> shell1 >> shell2 >> guess;
    swap(shells[shell1 - 1], shells[shell2 - 1]);
    ++points[shells[guess - 1] - 1];
  }
  
  cout << max({points[0], points[1], points[2]}) << '\n';

  return 0;
}
