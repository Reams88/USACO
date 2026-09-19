#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);

  int t;
  cin >> t;

  for(int times = 0; times < t; ++times) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    vector<int> diff(n + 1, 0);
    for(int k = 1; k <= n; ++k) {
      long long start = 1LL * k * arr[k-1];
      long long end = start + k - 1;
      if(start < n) {
        diff[start]++;
        if(end + 1 < n) {
          diff[end + 1]--;
        }
      }
    }

    vector<int> res;
    int current_coverage = 0;
    for(int i = 0; i < n; ++i) {
      current_coverage += diff[i];
      if(current_coverage == 0) {
        res.push_back(i);
      }
    }

    cout << res.size() << endl;
    for(int el : res) cout << el << ' ';
    cout << endl;
  }


  return 0;
}
