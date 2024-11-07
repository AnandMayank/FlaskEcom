#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string canCandidateAWin(int n, int x, vector<int>& votesA, vector<int>& votesB) {
    int aWins = 0;
    vector<int> neededVotes;

    // Step 1: Count initial wins for candidate A and calculate needed votes for each state where B is winning
    for (int i = 0; i < n; ++i) {
        if (votesA[i] > votesB[i]) {
            aWins++;
        } else {
            neededVotes.push_back(votesB[i] - votesA[i] + 1);
        }
    }

    // Step 2: Determine the majority threshold
    int majorityNeeded = (n / 2) + 1;

    // If candidate A already has the majority
    if (aWins >= majorityNeeded) {
        return "YES";
    }

    // Step 3: Sort the additional votes needed to win each losing state
    sort(neededVotes.begin(), neededVotes.end());

    // Step 4: Try to convert losses into wins using Chef's available votes
    for (int additionalVotes : neededVotes) {
        if (x >= additionalVotes) {
            x -= additionalVotes;
            aWins++;
            if (aWins >= majorityNeeded) {
                return "YES";
            }
        } else {
            break; // No more votes available to flip states
        }
    }

    // If candidate A can't reach a majority with Chef's votes
    return "NO";
}

int main() {
    int t;
    cin >> t;
    vector<string> results;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> votesA(n), votesB(n);

        for (int i = 0; i < n; ++i) {
            cin >> votesA[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> votesB[i];
        }

        // Determine if candidate A can win for this test case
        results.push_back(canCandidateAWin(n, x, votesA, votesB));
    }

    // Output results for all test cases
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
