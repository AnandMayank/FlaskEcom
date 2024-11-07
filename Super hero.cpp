#include <bits/stdc++.h>
using namespace std;

#ifndef itzzRaghav
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 1e6;
  vector<int> prime(N + 1, 1), lp(N + 1, -1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= N; i++) {
    if (!prime[i]) continue;
    lp[i] = i;
    for (int j = i + i; j <= N; j += i) {
      prime[j] = 0;
      if (lp[j] == -1) lp[j] = i;
    }
  }
  
  auto solve = [&]() {
    int h, k;
    cin >> h >> k;

    int ans = 0;
    int x = h;

    while (x > 1) {
      x /= lp[x];
      ans++;
    }

    x = k;
    while (x > 1) {
      ans++;
      x /= 2;
    }

    cout << ans << "\n";
  };
  
  int t = 1;
  cin >> t;
  
  for (int tc = 1; tc <= t; tc++) {
    debug(Testcase, tc);
    solve();
    crndl;
  }
  
  return 0;
}