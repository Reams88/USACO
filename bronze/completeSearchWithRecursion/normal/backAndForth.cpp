#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;



int main() {
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
  
  vector<int> s1(10);
  for(int i = 0; i < 10; ++i) {
    cin >> s1[i];
  }

  vector<int> s2(10);
  for(int i = 0; i < 10; ++i) {
    cin >> s2[i];
  }

  set<vector<int>> poss;
  for(int i1 = 0; i1 < 10; ++i1) {
    vector<int> currPoss;
    vector<int> s1M = s1;
    vector<int> s2M = s2;
    currPoss.push_back(s1M[i1]);
    s2M.push_back(s1M[i1]);
    s1M.erase(s1M.begin() + i1);
    //cout << "i1 = " << i1 << endl;
    for(int j1 = 0; j1 < 11; ++j1) {
      //cout << "did i crash here?" << endl;
      vector<int> s1M1 = s1M;
      vector<int> s2M1 = s2M;
      currPoss.push_back(s2M1[j1]);
      s1M1.push_back(s2M1[j1]);
      s2M1.erase(s2M1.begin() + j1);
      //cout << "j1 = " << j1 << endl;
      for(int i2 = 0; i2 < 10; ++i2) {
        vector<int> s1M2 = s1M1;
        vector<int> s2M2 = s2M1;
        int temp3 = s1M2[i2];
        currPoss.push_back(temp3);
        //cout << "did i crash here?" << endl;
        s2M2.push_back(temp3);
        s1M2.erase(s1M2.begin() + i2);
        //cout << "i2 = " << i2 << endl;
        for(int j2 = 0; j2 < 11; ++j2) {
          currPoss.push_back(s2M2[j2]);
          //for(int el : currPoss) cout << el << ' ';
          //cout << endl;
          poss.insert(currPoss);
          //cout << "j2 = " << j2 << endl;
          currPoss.pop_back();
        }
        currPoss.pop_back();
      }
      currPoss.pop_back();
    }
  }

  //cout << "\n\n";
  set<int> vals;
  for(const auto& vec : poss) {
    int c1 = 1000;
    c1 -= vec[0]; // Tuesday (B1 to B2)
    c1 += vec[1]; // Wednesday (B2 to B1)
    c1 -= vec[2]; // Thursday (B1 to B2)
    c1 += vec[3]; // Friday (B2 to B1)

    vals.insert(c1);
  }

  cout << vals.size() << endl;

  return 0;
}
