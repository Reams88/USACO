#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Create and open the file
  ofstream outfile("cbarn.in");
  
  int n = 1000000;
  outfile << n << '\n';
  
  // Room 0 gets 1 cow
  outfile << 1 << '\n';
  
  // The next 999,998 rooms get 0 cows
  for (int i = 1; i < n - 1; ++i) {
    outfile << 0 << '\n';
  }
  
  // The final room gets 1 cow
  outfile << 1 << '\n';
  
  outfile.close();
  cout << "Massive 10^6 test file created successfully!" << '\n';
  
  return 0;
}
