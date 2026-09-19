#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
//#include <print>

using namespace std;
using ull = unsigned long long;

bool find(const vector<int>& flowers, int start, int end) {
  int sum = 0;
  set<int> helper;
  for(int i = start; i < end + 1; ++i) {
    //cout << flowers[i] << sum << endl;
    sum += flowers[i];
    helper.insert(flowers[i]);
  }
  //println("is sum%((end+1)-(start+1) true = {} or is helper.count(sum/((end+1)-(start+1))) true = {}/{}", sum%((end+1)-(start+1)), sum, ((end+1)-(start+1)+1));
  int total_elements = end - start + 1;

  double num = (double)sum / total_elements; 

  if ((sum % total_elements != 0) || !helper.count(num)) return false;

  return true;
}

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<int> flowers(n, 0);
  for(int i = 0; i < n; ++i) cin >> flowers[i];

  int counter = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i; j < n; ++j) {
      //println("range ({},{}) is", i, j);
      if(i == j || find(flowers, i, j)) { 
        ++counter;
        //cout << "good" << endl;
      }
      //cout << endl;
    }
  }

  cout << counter << endl;

  return 0;
}
