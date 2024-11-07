#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int largest_div(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return n / 2; 
    int sqrt_n = sqrt(n);
    for (int i = sqrt_n; i >= 1; --i) {
        if (n % i == 0) {
            int d = n / i;
            if (d < n) return d;
            return i;
        }
    }
    return 1;  
}


int steps(int h) {
    int cnt = 0;
    while (h > 1) {
        h = largest_div(h);
        cnt++;
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int H, K;
        cin >> H >> K;
        
        int max_steps = 0;
        for (int m = 1; m <= K; m++) {
            int h = H * m;
            max_steps = max(max_steps, steps(h));
        }
        cout << max_steps << endl;
    }
    return 0;
}
