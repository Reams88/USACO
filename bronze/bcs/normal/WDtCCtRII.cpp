#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
//#include <print>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  string road;
  cin >> road;

  set<char> repeats;
  int res = 0;
  for(int i = 0; i < 52; ++i) {
    if(repeats.count(road[i])) continue;
    int j = (i == 51) ? 0 : i+1;
    while(road[i] != road[j]) {
      ++j;
    }
    for(int k = (i == 51) ? 0 : i+1; k != j; (k == 51) ? k = 0 : ++k) {
      for(int l = (j == 51) ? 0 : j+1; l != i; (l == 51) ? l = 0 : ++l) {
        if(road[k] == road[l]) {
          ++res;
          //println("We are between {} and its {} and {} and its {}, we are on the {} letter {} inside and {} letter {} outside res = {}", i, road[i], j, road[j], k, road[k], l, road[l], res);
          break;
        }
      }
    }
    repeats.insert(road[i]);
  }

  cout << res/2 << endl;

  return 0;
}
