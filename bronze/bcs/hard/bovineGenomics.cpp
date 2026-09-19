#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;
using ull = unsigned long long;

template<class T>
void print(const T& cont) {
  for(const auto& el : cont) cout << el << endl;
}

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n;
  cin >> n;

  int m;
  cin >> m;

  vector<string> spotty(n);
  vector<string> plain(n);
  for(int i = 0; i < n*2; ++i) {
    string str;
    cin >> str;
    (i < n) ? spotty[i] = str : plain[i%n] = str;
  }
  //print(spotty);
  //print(plain);
  
  int res = 0;
  for(int i = 0; i != m-2; ++i) {
    for(int j = i+1; j != m-1; ++j) {
      if(j <= i) continue;
      for(int k = j+1; k != m; ++k) {
        if(k <= j || k <= i) continue;
        int counter = 0;
        set<string> spottyS;
        set<string> plainS;
        set<string> all;
        bool bad = false;
        for(int l = 0; l < n; ++l) {
          string spottyStr = "";
          spottyStr += spotty[l][i];
          spottyStr += spotty[l][j];
          spottyStr += spotty[l][k];
          
          string plainStr = "";
          plainStr += plain[l][i];
          plainStr += plain[l][j];
          plainStr += plain[l][k];

          if(plainStr == spottyStr) {
            bad = true;
            break;
          }
          
          spottyS.insert(spottyStr);
          plainS.insert(plainStr);
        }
        if(bad) continue;
        int len = spottyS.size() + plainS.size();
        all.merge(spottyS);
        all.merge(plainS);
        //cout << "merged: " << endl;
        //print(all);
        //cout << all.size() << ' ' << len << endl;
        if(all.size() == len) {
          ++res;
          //cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
        }
        //cout << endl;
      }
    }
  }
  // 254 264 265 274 275 276

  cout << res << endl;

  return 0;
}
