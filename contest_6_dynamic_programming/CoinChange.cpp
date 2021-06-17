#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

vector<int> C;

ll N, L;

ll mem[51][251];

ll dp(int m, int n) {
  // m = index of coin, n = current sum
  if (m < 0 && n >= 1)
    return 0;

  if (n == 0)
    return 1;
  if (n < 0)
    return 0;

  if (mem[m][n] != -1)
    return mem[m][n];

  return mem[m][n] = dp(m - 1, n) + dp(m, n - C[m]);
}

int main() {
  cin >> N >> L;
  C.resize(L);
  rep(i, L) cin >> C[i];

  memset(mem, -1, sizeof mem);
  cout << dp(L - 1, N) << '\n';
}
