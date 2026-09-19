#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    if (!(cin >> S >> T)) return 0;

    int m = T.length();

    // 1. Compute the KMP Prefix Array for the bad word (T)
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && T[i] != T[j]) {
            j = pi[j - 1]; // Fall back
        }
        if (T[i] == T[j]) {
            j++;
        }
        pi[i] = j;
    }

    string result = "";
    
    // 2. State stack: stores the length of the matched prefix 
    // corresponding to each character in our `result` string.
    // We initialize it with 0 to represent the start of the string.
    vector<int> match_len = {0}; 

    // 3. Process the main string character by character
    for (char c : S) {
        result += c; // Push the character
        
        // Get the KMP state from the character right before this one
        int j = match_len.back(); 
        
        // Standard KMP state transition
        while (j > 0 && c != T[j]) {
            j = pi[j - 1];
        }
        if (c == T[j]) {
            j++;
        }
        
        // Push the new state onto the stack
        match_len.push_back(j);

        // 4. If our state equals the length of the bad word, we found a match!
        if (j == m) {
            // Instantly chop the bad word off the result string
            result.resize(result.size() - m);
            // Instantly rewind our KMP state tracker!
            match_len.resize(match_len.size() - m);
        }
    }

    cout << result << '\n';

    return 0;
}
