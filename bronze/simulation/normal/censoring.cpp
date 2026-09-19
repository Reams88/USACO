#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string line;
  cin >> line;

  string code;
  cin >> code;

  bool onto = false;
  int possibleIndx = 0;
  while (line.find(code) != string::npos) {
    line.erase(line.find(code), code.size());
  }

  cout << line << endl;

  return 0;
}
