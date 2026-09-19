#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int,int>> table(n);
  for(int i = 0; i < n; ++i) {
    cin >> table[i].first >> table[i].second;
  }

  sort(table.begin(), table.end(), [](auto a, auto b) {
    return a.first < b.first;
  });

  //for(const auto& par : table) cout << par.first << ' ' << par.second << endl;

  int time = 0;
  for(int i = 0; i < n; ++i) {
    if(time < table[i].first) {
      time += table[i].first - time;
      //cout << time << endl;
    }
    //time += table[i].first;
    //cout << time << endl;
    time += table[i].second;
    //cout << time << endl;
    //cout << endl;
  }

  cout << time << endl;



  return 0;
}
