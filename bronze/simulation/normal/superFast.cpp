#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono> // Kept the stopwatch so you can test it!

using namespace std;
using ull = unsigned long long;

int main() {
  // freopen("cbarn.in", "r", stdin);
  // freopen("cbarn.out", "w", stdout);

  ull n;
  cin >> n;

  vector<ull> rooms(n);
  ull total_cows = 0;
  ull current_distance = 0;

  // 1. Read input and calculate the baseline for unlocking Room 0
  for (ull i = 0; i < n; ++i) {
    cin >> rooms[i];
    total_cows += rooms[i];
    // Cows in room i have to walk i doors if we start at room 0
    current_distance += i * rooms[i]; 
  }

  // Start the stopwatch AFTER I/O is done
  auto start = chrono::high_resolution_clock::now();

  ull min_distance = current_distance;

  // 2. The O(N) Sliding Window: shift the unlocked door one by one
  for (ull i = 1; i < n; ++i) {
    // The Magic Formula
    // - Everyone gets 1 door closer (-total_cows)
    // - Except the cows in the room we just passed, who now walk the whole barn (+ N * rooms[i-1])
    current_distance = current_distance - total_cows + (n * rooms[i - 1]);
    
    min_distance = min(min_distance, current_distance);
  }

  // Stop the stopwatch
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

  // Print the actual answer
  cout << min_distance << '\n';
  
  // Print the benchmark
  cout << "Time taken: " << duration.count() << " milliseconds\n";

  return 0;
}
