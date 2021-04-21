#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, t;
vector<double> x, v;

bool decrease(double &c) {
  /* true if we must decrease c, else false */
  double time = 0;
  rep(i, n) {
    if (v.at(i) + c <= 0.0)
      return false;
    time += x.at(i) / (v.at(i) + c);
  }

  if (time < t)
    return true;

  return false;
}

int main() {

  cout.setf(ios::fixed);
  cout.precision(10);

  cin >> n >> t;

  x.resize(n);
  v.resize(n);

  rep(i, n) { cin >> x.at(i) >> v.at(i); }

  double m;
  double l = -100000000.0;
  double r = 100000000.0;

  rep(i, 10000) {
    m = (l + r) * .5;
    if (decrease(m))
      r = m;
    else
      l = m;
  }

  cout << m << endl;
}
