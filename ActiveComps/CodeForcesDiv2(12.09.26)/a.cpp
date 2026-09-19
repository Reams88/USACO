#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);


  int t = 0;
  cin >> t;

  for(int times = 0; times < t; ++times) {
    int n;
    cin >> n;
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; ++i) {
      int temp;
      cin >> temp;
      (temp) ? ++ones : ++zeros;
    }
    if(ones >= zeros) cout << "Bessie" << endl;
    else cout << "Elsie" << endl;
  }


  return 0;
}
