#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
using namespace std;

int N;
double R, S, X, Y, W; // S = n of sides, R = minimum value, X = positive events,
                      // Y = total events, W = bet multiplier factor
ll factorial(int n) {
  ll num = 1;
  rep(i, n) { num *= i + 1; }

  return num;
}

double binomial(int n, int k, double p) {
  return (factorial(n) / (factorial(k) * factorial(n - k))) * pow(p, k) *
         pow(1 - p, n - k);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--) {
    cin >> R >> S >> X >> Y >> W;

    double exp_value = 0;
    for (int i = X; i <= Y; i++) {
      double p = (S - R + 1) / (S);
      exp_value += binomial(Y, i, p);
    }

    if (exp_value * W > 1)
      cout << "yes" << '\n';
    else
      cout << "no" << '\n';
  }
}
