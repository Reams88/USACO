#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool checker(const vector<string>& perm, const vector<pair<string, string>>& constraints) {
  for (const auto& edge : constraints) {
    string c1 = edge.first;
    string c2 = edge.second;
    
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < 8; ++i) {
      if (perm[i] == c1) pos1 = i;
      if (perm[i] == c2) pos2 = i;
    }
    
    if (abs(pos1 - pos2) != 1) {
      return false;
    }
  }
  return true;
}

void search(const vector<string>& idealOrder, vector<string>& permutation, const vector<pair<string, string>>& constraints, vector<bool>& chosen) {
  if (permutation.size() == 8) {
    if (checker(permutation, constraints)) {
      for (const string& str : permutation) {
        cout << str << endl;
      }
      exit(0);
    }
    return;
  }

  for (int i = 0; i < 8; i++) {
    if (chosen[i]) continue;
    chosen[i] = true;
    permutation.push_back(idealOrder[i]);
    search(idealOrder, permutation, constraints, chosen);
    chosen[i] = false;
    permutation.pop_back();
  }
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  int n;
  if (!(cin >> n)) return 0;

  vector<pair<string, string>> constraints;
  for (int i = 0; i < n; ++i) {
    string use1, garb, use2;
    cin >> use1 >> garb >> garb >> garb >> garb >> use2;
    constraints.push_back({use1, use2});
  }

  vector<string> idealOrder = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
  vector<string> permutation;
  vector<bool> chosen(8, false);

  search(idealOrder, permutation, constraints, chosen);

  return 0;
}

