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
        int result =0 ;
        int r=0;
        int l=0;
        if (s[0] == s[n - 1]) {
            cout << 0 << endl;  // Already beautiful
        } else {
          if ( s[1]==0 || s[n-2] == 0){ 
           int result= 1;
          }
          else{
            for ( int i=1 ; i< n; i++){
                if (s[i]==0 ){
                r++;
                    break;
                }
                for ( int j=n-2; j>=0; j--){
                    if ( s[j]== 0){
                        l++;
                        break;
                    }
                }
            }
          }
            
            // Compute the number of shifts
         result = min(l, r);
            cout << result << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
