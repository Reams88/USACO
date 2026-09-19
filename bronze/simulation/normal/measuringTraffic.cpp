#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
#define lowb (sensors[i].second.first)
#define highb (sensors[i].second.second)
#define gate (sensors[i].first)


int main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<pair<string, pair<int, int>>> sensors(n);

  for(int i = 0; i < n; ++i) {
    cin >> sensors[i].first >> sensors[i].second.first >> sensors[i].second.second;
  }

  int lowout = -99999, highout = 99999;
  int lowin = -99999, highin = 99999;

  for(int i = 0; i < n; ++i) {
    if(gate == "none") {
      lowout = max(lowout, lowb);
      highout = min(highout, highb);
    } else if(gate == "on") {
      lowout = lowout + lowb;
      highout = highout + highb;
    } else {
      lowout = lowout - highb;
      highout = highout - lowb;
      lowout = max(0, lowout); 
    }
  } 
  
  for(int i = n - 1; i >= 0; --i) {
    if(gate == "none") {
      lowin = max(lowin, lowb);
      highin = min(highin, highb);
    } else if(gate == "off") {
      lowin = lowin + lowb;
      highin = highin + highb;
    } else {
      lowin = lowin - highb;
      highin = highin - lowb;
      lowin = max(0, lowin); 
    }
  }

  cout << lowin << " " << highin << "\n" << lowout << " " << highout << "\n";    

  return 0;
}
