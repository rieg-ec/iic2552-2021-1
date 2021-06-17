#include <iostream>
#include <math.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;

  if (N % 2 != 0) {
    cout << 0 << '\n';
    return 0;
  }

  long long sol = 1;
  rep(_, N / 2) { sol *= 2; }
  cout << sol << '\n';
}
