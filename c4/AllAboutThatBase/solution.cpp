#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

int N;
int R, S, X, Y, W; // S = n of sides, R = minimum value, X = positive events,
                   // Y = total events, W = bet multiplier factor
int factorial(int n) {
  if (n < 1)
    return 1;

  return n * factorial(n - 1);
}

double binomial() { return 0.5; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--) {
    cin >> R >> S >> X >> Y >> W;

    cout << factorial(6);
  }
}
