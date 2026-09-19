#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n;
  cin >> n;

  set<int> nums;
  for(int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.insert(num);
  }

  cout << nums.size() << endl;

  return 0;
}
