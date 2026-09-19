#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int counter = 0;
  int numberOfI = 0;
  while(numberOfI != (n-1)) {
    numberOfI = n-1;
    for(int i = 0; i < n-1; ++i) {
      if(arr[i] > arr[i+1]) {
        --numberOfI;
        ++counter;
        swap(arr[i], arr[i+1]);
      }
    }
  }

  //for(int num : arr) cout << num << ' ';
  //cout << endl;

  cout << "Array is sorted in " << counter << " swaps." << "\nFirst Element: " << *arr.begin()
       << "\nLast Element: " << *arr.rbegin() << endl;

  return 0;
}
