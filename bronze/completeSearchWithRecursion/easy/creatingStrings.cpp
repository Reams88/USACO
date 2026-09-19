#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

template<class T>
void printer(const T& cont) {
  for(const auto& el : cont) cout << el;
  cout << endl;
}

void search(int n, string& word, vector<char>& list, vector<char>& perm, vector<string>& permlist, int& num) {
  if(perm.size() == n) {
    string permutation;
    for(const auto el : perm) permutation += el;
    permlist.push_back(permutation);
    ++num;
  } else {
    for(int i = 0; i < 26; ++i) {
      if(list[i] == 0) continue;
      --list[i];
      perm.push_back((char)(i + 'a'));
      search(n, word, list, perm, permlist, num);
      ++list[i];
      perm.pop_back();
    }
  }
}

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  string word;
  cin >> word;

  vector<char> list(26);
  for(const auto& letter : word) {
    ++list[letter - 97];
  } 

  vector<char> chosen(26);
  vector<string> permlist;
  int num = 0;
  vector<char> perm;
  search(word.size(), word, list, perm, permlist, num);

  cout << num << endl;
  for(const auto& str : permlist) cout << str << endl;

  return 0;
}
