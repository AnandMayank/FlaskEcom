#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Custom function to compute GCD of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular inverse of x under MOD
long long modular_inverse(long long x, int mod) {
    long long result = 1, base = x;
    int exponent = mod - 2;  // Fermat's little theorem, since MOD is prime
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

// Function to calculate probability of Alice winning the game
long long alice_winning_probability(int N, int D, const vector<int>& piles) {
    // Calculate the Nim-sum of the piles
    int nim_sum = 0;
    for (int pile : piles) {
        nim_sum ^= pile;
    }

    // Calculate the probability of Alice winning the dice roll
    // P = D * (D + 1) / 2, Q = D * D
    long long P = (1LL * D * (D + 1) / 2) % MOD;
    long long Q = (1LL * D * D) % MOD;

    // Simplify P and Q by dividing by their GCD
    long long gcd_pq = gcd(P, Q);
    P /= gcd_pq;
    Q /= gcd_pq;

    // Calculate the result as P * Q^(-1) % MOD
    long long Q_inv = modular_inverse(Q, MOD);
    long long result = (P * Q_inv) % MOD;

    // If nim_sum is zero, Alice is in a losing position if both play optimally
    return nim_sum == 0 ? 0 : result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;
        vector<int> piles(N);
        for (int i = 0; i < N; ++i) {
            cin >> piles[i];
        }
        cout << alice_winning_probability(N, D, piles) << endl;
    }
    return 0;
}
