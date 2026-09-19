#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

void row(int& one, int& two, const vector<string>& board, set<set<char>>& letters) {
  
  for(const auto& word : board) {
    int sizePrev = letters.size();
    
    set<char> thisC = {word[0], word[1], word[2]};

    letters.insert(thisC);

    if(thisC.size() == 1 && letters.size() - sizePrev == 1) ++one;
    if(letters.size() - sizePrev == 1 && thisC.size() == 2) ++two;
  }

  return;
}

void column(int& one, int& two, const vector<string>& board, set<set<char>>& letters) {
  
  for(int i = 0; i < 3; ++i) {
    int sizePrev = letters.size();
    
    set<char> thisC = {board[0][i], board[1][i], board[2][i]};

    letters.insert(thisC);

    if(thisC.size() == 1 && letters.size() - sizePrev == 1) ++one;
    if(letters.size() - sizePrev == 1 && thisC.size() == 2) ++two;
  }

  return;
}

void diag(int& one, int& two, const vector<string>& board, set<set<char>>& letters) {
  int sizePrev = letters.size();
    
  set<char> thisC = {board[0][0], board[1][1], board[2][2]};

  letters.insert(thisC);

  if(thisC.size() == 1 && letters.size() - sizePrev == 1) ++one;
  if(letters.size() - sizePrev == 1 && thisC.size() == 2) ++two;
  return;
}

void rdiag(int& one, int& two, const vector<string>& board, set<set<char>>& letters) {
  int sizePrev = letters.size();
    
  set<char> thisC = {board[0][2], board[1][1], board[2][0]};

  letters.insert(thisC);

  if(thisC.size() == 1 && letters.size() - sizePrev == 1) ++one;
  if(letters.size() - sizePrev == 1 && thisC.size() == 2) ++two;
  return;
}

int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  
  vector<string> board(3, " ");
  for(int i = 0; i < 3; ++i) {
    cin >> board[i];
  }

  int one = 0, two = 0;
  set<set<char>> letters;

  row(one, two, board, letters);
  column(one, two, board, letters);
  diag(one, two, board, letters);
  rdiag(one, two, board, letters);

  cout << one << '\n' << two << endl;

  return 0;
}
