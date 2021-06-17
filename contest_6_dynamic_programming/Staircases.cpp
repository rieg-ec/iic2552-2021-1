#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)

ll N, DP[510][510];

ll dp(int n, int h) {

  if (n == 0)
    return 1;
  if (n <= h)
    return 0;

  if (DP[n][h] != -1) {
    return DP[n][h];
  }

  ll sol = 0;
  for (ll i = h + 1; i <= n; i++) {
    sol += dp(n - i, i);
  }

  DP[n][h] = sol;
  return sol;
}

int main() {
  cin >> N;

  memset(DP, -1, sizeof DP);
  cout << dp(N, 0) - 1 << '\n';
}
