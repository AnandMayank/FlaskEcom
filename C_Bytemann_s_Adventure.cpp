#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        } 
         

        vector<int> l(n, 1), r(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (abs(h[i] - h[i - 1]) <= 1) {
                r[i] = r[i - 1] + 1;
            }
        }
    
        for (int i = n - 2; i >= 0; --i) {
            if (abs(h[i] - h[i + 1]) <= 1) {
                l[i] = l[i + 1] + 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, l[i] + r[i] - 1);
        }
        
        cout <<ans<< endl;
    }
}

int main() {
    solve();
    return 0;
}
