#include <bits/stdc++.h>
using namespace std;

#ifndef itzzRaghav
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

#define int long long

int32_t main() {vector<int> left(n, 1), right(n, 1);
        
        // Compute the 'right' array: maximum buildings we can cover moving right from each building
        for (int i = 1; i < n; ++i) {
            if (abs(heights[i] - heights[i - 1]) <= 1) {
                right[i] = right[i - 1] + 1;
            }
        }
        
        // Compute the 'left' array: maximum buildings we can cover moving left from each building
        for (int i = n - 2; i >= 0; --i) {
            if (abs(heights[i] - heights[i + 1]) <= 1) {
                left[i] = left[i + 1] + 1;
            }
        }
        
        // Find the maximum value of (left[i] + right[i] - 1)
        int max_buildings = 0;
        for (int i = 0; i < n; ++i) {
            max_buildings = max(max_buildings, left[i] + right[i] - 1);
        }
        
        cout << max_buildings << endl;
    }

int main() {
    solve();
    return 0;
}



