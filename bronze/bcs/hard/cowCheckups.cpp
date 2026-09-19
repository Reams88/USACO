#include <iostream>
//#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
using ull = unsigned long long;

void printer(const auto& cont) {
  for(int num : cont) cout << num << ' ';
  cout << endl;
}

int checkerLong(const auto& our, const auto& des, int n) {
  int same = 0;
  for(int l = 0; l < n; ++l) if(our[l] == des[l]) ++same;
  return same;
}

int checker(const auto& our, const auto& des, int n, int maxSame, int indx1, int indx2) {
  int same = maxSame;
  if(our[indx1] == des[indx1]) ++same;
  if(our[indx2] == des[indx2]) ++same;
  return same;
}

void middle(int& i1, int& i2) {
  if((i1 + i2) % 2 == 0) {
    //cout << " middle ";
    i1 = ((i1 + i2) / 2)-1;
    i2 = i1 + 2;
  } else {
    //cout << " no middle ";
    i1 = (i1 + i2) / 2;
    i2 = i1 + 1;
  }
}

void swaper(auto& our, int n, int indx1, int indx2, auto& res, auto& des, int baseMatches) {
  middle(indx1, indx2);
  //cout << indx1 << ' ' << indx2 << endl;
  //printer(our);
  // Pass 'baseMatches' (the total matches of the original array) into swaper
  int currentMatches = baseMatches; 
  for(; indx1 >= 0; --indx1, ++indx2){
    if(indx2 > n-1) continue;
    if (our[indx1] == des[indx1]) --currentMatches;
    if (our[indx2] == des[indx2]) --currentMatches;
    swap(our[indx1], our[indx2]);
    if (our[indx1] == des[indx1]) ++currentMatches;
    if (our[indx2] == des[indx2]) ++currentMatches;
    ++res[currentMatches];
  }
}

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<int> our;
  vector<int> des;
  for(int i = 0; i < 2*n; ++i) {
    int num;
    cin >> num;
    (i < n) ? our.push_back(num) : des.push_back(num);
  }

  vector<int> res(n+1, 0);
  //vector<int> add(n-2, 0);
  int baseMatches = checkerLong(our, des, n);
  res[baseMatches] = n;
  //our.insert(our.end(), add.begin(), add.end());
  for(int i = 1; i < n + (n - 2); ++i) {
    vector<int> ourC = our;
    //cout << i << ' ';
    swaper(ourC, n, 0, i, res, des, baseMatches);
  }

  for(auto num : res) cout << num << endl;

  return 0;
}
