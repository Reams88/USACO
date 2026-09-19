#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

void sim(const vector<vector<string>>& board, int n, bool flag) {
  vector<int> similarity(4);
  for(int i = 0; i < 4; ++i) { 
    for(int j = 0; j < n/2; ++j) {
      for(int k = 0; k < n/2; ++k) {
        switch(i){
          case 0:
            if(board[i][j][k] == board[1][j][n/2 - k - 1]) ++similarity[i];
            if(board[i][j][k] == board[3][n/2 - j - 1][k]) ++similarity[i];
            if(board[i][j][k] == board[2][n/2 - j - 1][n/2 - k - 1]) ++similarity[i];
            break;
          case 1:
            if(board[i][j][k] == board[0][j][n/2 - k - 1]) ++similarity[i];
            if(board[i][j][k] == board[2][n/2 - j - 1][k]) ++similarity[i];
            if(board[i][j][k] == board[3][n/2 - j - 1][n/2 - k - 1]) ++similarity[i];
            break;
          case 2:
            if(board[i][j][k] == board[3][j][n/2 - k - 1]) ++similarity[i];
            if(board[i][j][k] == board[1][n/2 - j - 1][k]) ++similarity[i];
            if(board[i][j][k] == board[0][n/2 - j - 1][n/2 - k - 1]) ++similarity[i];
            break;
          case 3:
            if(board[i][j][k] == board[2][j][n/2 - k - 1]) ++similarity[i];
            if(board[i][j][k] == board[0][n/2 - j - 1][k]) ++similarity[i];
            if(board[i][j][k] == board[1][n/2 - j - 1][n/2 - k - 1]) ++similarity[i];
            break;
        }
      }
    }
  }
  int middle = 0;
  sort(similarity.begin(), similarity.end());
  //for(int num : similarity) cout << num << ' ';
  //cout << endl;
  if((similarity[2] + similarity[1])%2 == 0) middle = (similarity[2] + similarity[1])/2;
  else middle = similarity[1];
  //cout << middle << endl;
  int steps = 0;
  for(int i = 0; i < 4; ++i) {
    while(similarity[i] != middle) {
      (similarity[i] > middle) ? --similarity[i] : ++similarity[i];
      ++steps;
    }
  }
  cout << ((flag) ? steps/2 : steps);
  cout << endl;
  return;
}

int main() {
  //freopen("blist.in", "r", stdin);
  //freopen("blist.out", "w", stdout);
  
  int n, u;
  cin >> n >> u;

  //vector<string> tmp(n, " ");

  //for(int i = 0; i < n; ++i) {
    //cin >> tmp[i];
  //}

  vector<vector<string>> board(4, vector<string>(n/2, string(n/2, ' ')));
  
  int collIndx = 0, rowIndx = 0, quadIndx = 0;
  for(int j = 0; j < n; ++j) {
    for(int k = 0; k < n; ++k) {
      collIndx = k%(n/2);
      rowIndx = j%(n/2); 
      if(k < n/2 && j < n/2) quadIndx = 0;                                    //0|1
      if(k >= n/2 && j < n/2) quadIndx = 1;                                   //3|2
      if(k >= n/2 && j >= n/2) quadIndx = 2;
      if(k < n/2 && j >= n/2) quadIndx = 3;
      cin >> board[quadIndx][rowIndx][collIndx];
    }
  }

  vector<pair<int, int>> changes(u, {0,0});
  for(int i = 0; i < u; ++i) {
    cin >> changes[i].first >> changes[i].second;
  }

  sim(board, n, false);
  for(const auto& change : changes) {
    int nX = (change.first-1)%(n/2), nY = (change.second-1)%(n/2);
    if((change.first-1) < n/2 && (change.second-1) < n/2) quadIndx = 0;                                    //0|1
    if((change.first-1) >= n/2 && (change.second-1) < n/2) quadIndx = 3;                                   //3|2
    if((change.first-1) >= n/2 && (change.second-1) >= n/2) quadIndx = 2;
    if((change.first-1) < n/2 && (change.second-1) >= n/2) quadIndx = 1;
    /*
    for(int i = 0; i < 4; ++i) { 
      cout << i << endl;
      for(int j = 0; j < n/2; ++j) {
        for(int k = 0; k < n/2; ++k) {
          cout << board[i][j][k]; 
        }
        cout << endl;
      }
      cout << '\n' << '\n';
    }
    cout << '\n' << '\n' << '\n';
    */
    (board[quadIndx][nX][nY] == '.') ? board[quadIndx][nX][nY] = '#' : board[quadIndx][nX][nY] = '.';
    /*
    for(int i = 0; i < 4; ++i) { 
      cout << i << endl;
      for(int j = 0; j < n/2; ++j) {
        for(int k = 0; k < n/2; ++k) {
          cout << board[i][j][k]; 
        }
        cout << endl;
      }
      cout << '\n' << '\n';
    }
    */
    sim(board, n, true);
  }

  return 0;
}
