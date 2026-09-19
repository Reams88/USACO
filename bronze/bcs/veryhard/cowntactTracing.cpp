#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int t;
  cin >> t;

  string ill;
  cin >> ill;

  map<int, pair<int, int>> inter;
  for(int i = 0; i < t; ++i) {
    int time;
    cin >> time;
    cin >> inter[time].first;
    cin >> inter[time].second;
  }

  set<int> numOfP0;
  int lowestK = 99999;
  int highestK = -1;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j <= t + 1; ++j) {
      vector<pair<int, int>> cow(n, {0, 0});
      cow[i].first = 1;

      for(const auto& par : inter) {
        int c1 = par.second.first - 1;
        int c2 = par.second.second - 1;

        bool c1_was_infected = (cow[c1].first == 1);
        bool c2_was_infected = (cow[c2].first == 1);

        if (c1_was_infected) {
          if (cow[c1].second < j) {
            cow[c2].first = 1;
          }
          ++cow[c1].second;
        }

        if (c2_was_infected) {
          if (cow[c2].second < j) {
            cow[c1].first = 1;
          }
          ++cow[c2].second;
        }
      }

      string resstr = "";
      for(const auto& some : cow) {
        resstr += (char)(some.first + '0');
      }

      if(resstr == ill) {
        numOfP0.insert(i);
        lowestK = min(lowestK, j);
        highestK = max(highestK, j);
      }
    }
  }

  cout << numOfP0.size() << " " << lowestK << " ";
  if (highestK > t) {
    cout << "Infinity\n";
  } else {
    cout << highestK << "\n";
  }

  return 0;
}
