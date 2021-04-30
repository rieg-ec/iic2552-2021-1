#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

int N, K;

vector<double> S, D;

double f(double t) {
  double min_x = 1e20, max_x = -1e20;

  rep(i, N) {
    double x = D.at(i) + S.at(i) * t;
    min_x = min(min_x, x);
    max_x = max(max_x, x);
  }

  return max_x - min_x;
}

int main() {
  cout.precision(6);
  cout.setf(ios::fixed);

  cin >> N >> K;
  S.resize(N), D.resize(N);
  rep(i, N) cin >> S.at(i) >> D.at(i);

  double L = 0, R = K;
  rep(_, 1000) {
    double t = (R - L) / 3, m1 = L + t, m2 = R - t;
    double f1 = f(m1), f2 = f(m2);
    if (f1 <= f2)
      R = m2;
    if (f1 >= f2)
      L = m1;
  }

  cout << f((L + R) * .5) << endl;
}
