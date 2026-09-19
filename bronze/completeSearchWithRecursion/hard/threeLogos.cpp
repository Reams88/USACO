#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> coords(3, {0, 0, 'A'});

  int totalArea = 0;
  for (int i = 0; i < 3; ++i) {
    cin >> coords[i][0] >> coords[i][1];
    coords[i][2] += i;
    totalArea += coords[i][0] * coords[i][1];
  }

  int maxLen = 0;
  while (maxLen * maxLen < totalArea) {
    maxLen++;
  }

  if (maxLen * maxLen != totalArea) {
    cout << -1 << endl;
    return 0;
  }

  int indx = -1;
  for (int i = 0; i < 3; ++i) {
    if (coords[i][0] == maxLen || coords[i][1] == maxLen) {
      indx = i;
      if (coords[i][0] < coords[i][1]) swap(coords[i][0], coords[i][1]);
      break;
    }
  }

  if (indx == -1) {
    cout << -1 << endl;
    return 0;
  }

  char symb = coords[indx][2];
  int impy = coords[indx][1];

  vector<vector<char>> board(maxLen, vector<char>(maxLen, 'D'));

  for (int i = 0; i < impy; ++i) {
    for (int j = 0; j < maxLen; ++j) {
      board[i][j] = symb;
    }
  }

  coords.erase(coords.begin() + indx);

  bool ok = false;
  for (int r0 = 0; r0 < 2; ++r0) {
    for (int r1 = 0; r1 < 2; ++r1) {
      int w0 = coords[0][r0], h0 = coords[0][1 - r0];
      int w1 = coords[1][r1], h1 = coords[1][1 - r1];

      if (w0 == maxLen && w1 == maxLen && impy + h0 + h1 == maxLen) {
        ok = true;
        for (int i = impy; i < impy + h0; ++i) {
          for (int j = 0; j < maxLen; ++j) {
            board[i][j] = coords[0][2];
          }
        }
        for (int i = impy + h0; i < maxLen; ++i) {
          for (int j = 0; j < maxLen; ++j) {
            board[i][j] = coords[1][2];
          }
        }
        break;
      }

      if (w0 + w1 == maxLen && h0 == maxLen - impy && h1 == maxLen - impy) {
        ok = true;
        for (int i = impy; i < maxLen; ++i) {
          for (int j = 0; j < w0; ++j) {
            board[i][j] = coords[0][2];
          }
        }
        for (int i = impy; i < maxLen; ++i) {
          for (int j = w0; j < maxLen; ++j) {
            board[i][j] = coords[1][2];
          }
        }
        break;
      }
    }
    if (ok) break;
  }

  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  cout << maxLen << endl;
  for (int i = 0; i < maxLen; ++i) {
    for (int j = 0; j < maxLen; ++j) {
      cout << board[i][j];
    }
    cout << endl;
  }

  return 0;
}
