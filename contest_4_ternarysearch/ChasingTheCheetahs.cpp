#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

int N;
vector<int> s, v;

double f(double t) {
  double m = 1e18, M = 0;
  rep(i, N) {
    double x = (t - s.at(i)) * v.at(i);
    m = min(m, x), M = max(M, x);
  }

  return M - m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(3);

  while (cin >> N && N) {
    s.resize(N), v.resize(N);
    rep(i, N) { cin >> s.at(i) >> v.at(i); }

    double l = *max_element(s.begin(), s.end());
    double r = 1e9;
    rep(i, 100) {
      double t = (r - l) / 3, m1 = l + t, m2 = r - t;
      double f1 = f(m1), f2 = f(m2);
      if (f1 <= f2)
        r = m2;
      if (f1 >= f2)
        l = m1;
    }

    cout << f((l + r) / 2) << endl;
  }
}
