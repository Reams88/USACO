#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long;

int main() {
  int x, y;
  
  cin >> x >> y;
  
  int distance = 0;
  int factor = 1, currx = x, prevx = x;
  for (int i = 1; (x < y) ? currx < y : currx > y; ++i) {
    (i % 2 == 0) ? currx = x - factor : currx = x + factor;
    distance += abs(currx - prevx);
    prevx = currx;
    factor *= 2;
  }

  cout << distance - abs(currx - y) << endl;
  
  return 0;
}
