#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("test", "r", stdin);
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  ull n;
  cin >> n;

  vector<int> coords(n);
  for(int i = 0; i < n; ++i) {
    cin >> coords[i];
  }

  sort(coords.begin(), coords.end());
  //for(int num : coords) cout << num << ' ';
  //cout << endl;

  int maxD = 0;
  for(int i = 0; i < n; ++i) {
    int coord = i;
    int leftC = coord - 1;
    bool isOkl = false;
    if (coord != 0) {
      leftC = coord - 1;
      isOkl = true;
    }

    int rightC = coord + 1;
    bool isOkr = false;
    if (coord != n - 1) {
      rightC = coord + 1;
      isOkr = true;
    }

    int currD = 1;
    if (isOkl) {
      int rad = 1;
      int curr_coord = coord;
      while (curr_coord > 0) {
        int next_coord = curr_coord;
        while (next_coord - 1 >= 0 && coords[curr_coord] - coords[next_coord - 1] <= rad) {
          next_coord--;
        }
        if (next_coord == curr_coord) break;
        currD += (curr_coord - next_coord);
        curr_coord = next_coord;
        rad++;
      }
    }
    if (isOkr) {
      int rad = 1;
      int curr_coord = coord;
      while (curr_coord < n - 1) {
        int next_coord = curr_coord;
        while (next_coord + 1 < n && coords[next_coord + 1] - coords[curr_coord] <= rad) {
          next_coord++;
        }
        if (next_coord == curr_coord) break;
        currD += (next_coord - curr_coord);
        curr_coord = next_coord;
        rad++;
      }
    }
    maxD = max(currD, maxD);
  }

  cout << maxD << endl;

  return 0;
}
