#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Length of the binary sequence
        string s;
        cin >> s;  // The binary sequence
        
        // Case when the first and last elements are already the same
        if (s[0] == s[n - 1]) {
            cout << 0 << endl;
            continue;
        }

        // If the second or second-last element is '0', immediately output 1
        if (s[1] == '0' || s[n - 2] == '0') {
            cout << 1 << endl;
            continue;
        }

        // Now we need to find the positions of the first and last '1'
        int r = -1, l = -1;

        // Find the first '1' from index 1 to n-1
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                r = i;
                break;
            }
        }

        // Find the last '1' from index n-2 to 0
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1') {
                l = i;
                break;
            }
        }

        // The minimum number of shifts required is the minimum of the shifts needed to
        // bring the first '1' to the first position or the last '1' to the last position
        int result = min(r, n - 1 - l);
        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}
