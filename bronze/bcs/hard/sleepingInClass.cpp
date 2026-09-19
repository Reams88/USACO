#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
using ull = unsigned long long;

template<class T>
void print(const T& cont) {
  for(const auto& el : cont) cout << el << ' ';
  cout << endl;
}

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);

  int times;
  cin >> times;

  for(int t = 0; t < times; ++t) {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) {
      cin >> vec[i];
      sum += vec[i];
    }

    set<int> dividers;
    for(int i = 1; i*i <= sum; ++i) {
      if(sum % i == 0) {
        //cout << sum << ' ' << i << ' ' << sum/i << endl;
        dividers.insert(i);
        dividers.insert(sum/i);
      }
    }

    //print(dividers);
    //cout << endl;

    int moves = 0;
    for(int divider : dividers) {
      moves = 0;
      int currSum = -1;
      int i = 0;
      for(; i < n; ++i) {
        if(currSum == -1) {
          currSum += 1 + vec[i];
          //cout << currSum << ' ' << divider << endl;
          if(currSum == divider) {
            currSum = -1;
            continue;
          }
          else if(currSum > divider) break;
          else continue;
        } else {
          currSum += vec[i];
          ++moves;
          //cout << currSum << ' ' << divider << ' ' << moves << endl;
          if(currSum == divider) {
            currSum = -1;
            continue;
          }
          else if(currSum > divider) break;
          else continue;
        }
      }
      //cout << endl;
      if(i == vec.size()) break;
    }
    cout << moves << endl;
  }

  return 0;
}
