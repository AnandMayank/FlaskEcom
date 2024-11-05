#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper function to check if a substring starting at `pos` is "1100"
bool is_1100(const string &s, int pos) {
    if (pos >= 0 && pos + 3 < s.size()) {
        return s.substr(pos, 4) == "1100";
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        int q;
        cin >> s >> q;
        
        int n = s.size();
        int count_1100 = 0;
        
        // Initial count of "1100" in the entire string
        for (int i = 0; i <= n - 4; i++) {
            if (is_1100(s, i)) {
                count_1100++;
            }
        }
        
        // Process each query
        while (q--) {
            int i, v;
            cin >> i >> v;
            i--; // Convert to 0-based index
            
            // Step 1: Remove affected "1100" substrings in the range [i-3, i+3]
            for (int j = i - 3; j <= i; j++) {
                if (is_1100(s, j)) {
                    count_1100--;
                }
            }
            
            // Step 2: Apply the update
            s[i] = v + '0';
            
            // Step 3: Add back "1100" substrings in the range [i-3, i+3]
            for (int j = i - 3; j <= i; j++) {
                if (is_1100(s, j)) {
                    count_1100++;
                }
            }
            
            // Step 4: Output the result for this query
            if (count_1100 > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}
