#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("test", "r", stdin);
  //freopen("blist.out", "w", stdout);

  ull n;
  cin >> n;

  vector<ull> tuitions(n);
  for(int i = 0; i < n; ++i) {
    cin >> tuitions[i];
  }

  sort(tuitions.begin(), tuitions.end());

  ull maxSum = 0, maxT = 0;
  for(ull i = 0; i < n; ++i) {
    ull sum = (n - i) * tuitions[i];
    if(sum > maxSum) {
      maxSum = max(sum, maxSum);
      maxT = tuitions[i];
    }
  }

  cout << maxSum << ' ' << maxT << endl;


  return 0;
}
