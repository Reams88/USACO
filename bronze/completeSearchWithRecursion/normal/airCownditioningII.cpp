#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n, m;
  cin >> n >> m;

  vector<int> timeTable;
  int maxSize = 0;
  for(int i = 0; i < n; ++i) {
    int start, end, val;
    cin >> start >> end >> val;
    if(end > timeTable.size()) timeTable.resize(end, 0);
    for(int j = start-1; j < end; ++j) {
      timeTable[j] += val;
    }
  }

  vector<vector<int>> cond(m, {0, 0, 0, 0});
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < 4; ++j) cin >> cond[i][j];
  }

  int minprice = INT_MAX;
  for(int b = 0; b < (1<<m); ++b) {
    vector<int> subset;
    for(int i = 0; i < m; ++i) {
      if(b&(1<<i)) subset.push_back(i);
    }
    vector<int> timeCopy = timeTable;
    int price = 0;
    int number = 0;
    for(int indx : subset) {
      price += cond[indx][3];
      for(int i = cond[indx][0]-1; i < cond[indx][1]; ++i) {
        timeCopy[i] -= cond[indx][2];
      }
    }
    for(int el : timeCopy) if(el <= 0) ++number;
    if(number == timeCopy.size()) minprice = min(minprice, price);
  } 


  cout << minprice << endl;
  //for(auto el : timeTable) cout << el;
  //cout << endl;


  return 0;
}
