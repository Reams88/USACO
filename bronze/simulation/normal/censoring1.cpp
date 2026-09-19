#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;
using ull = unsigned long long;

int main() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);
  
  string line;
  cin >> line;

  string code;
  cin >> code;

  map<int, int> sim;
  int i = 0;
  while(i < line.size()){
    int codeI = 0;
    bool foundS = false;
    while(line[i] == code[codeI]) {
      foundS = true;
      ++codeI;
      ++i;
    }
    if(foundS){
      foundS = false;
      sim[i - codeI] = codeI;
    } else {
      ++i;
    }
  }

  while(!sim.empty()) {
    auto it = sim.begin();
    while (it != sim.end()) {
      if (it->second == code.size()) {
        line.erase(it->first, it->second);
        it = sim.erase(it);
      } else {
        if (line[it->first + it->second] == code[it->second]) {
          it->second++;
        }
        if (it->second == code.size()) {
          line.erase(it->first, it->second);
          it = sim.erase(it);
        } else {
          ++it;
        }
      }
    }
  }
 


  //for(const auto& elem : sim) {
  //  cout << elem.first << ' ' << elem.second << ", ";
  //}
  //cout << endl;

  cout << line << endl;;

  return 0;
}
