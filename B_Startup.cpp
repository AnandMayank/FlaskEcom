#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;

        // If there are no bottles, the maximum profit is 0
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }

        unordered_map<int, int> brand_costs; // brand -> total cost
        for (int i = 0; i < k; i++) {
            int b, c;
            cin >> b >> c;
            brand_costs[b] += c; // sum up costs for the same brand
        }

        vector<int> costs;
        for (const auto &entry : brand_costs) {
            costs.push_back(entry.second);
        }

        // If number of shelves is greater than or equal to unique brands
        if (n >= costs.size()) {
            int total = 0;
            for (int cost : costs) {
                total += cost; // take all costs
            }
            cout << total << endl;
        } else {
            // Sort costs in descending order
            sort(costs.rbegin(), costs.rend());

            // Sum the top n costs
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += costs[i];
            }
            cout << total << endl;
        }
    }

    return 0;
}
