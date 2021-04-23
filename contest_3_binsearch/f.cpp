#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<pair<double, double>> xv;

bool check(double &t) {
  for (unsigned i = 0; i < n - 1; i++) {
    double ri = xv.at(i).first + xv.at(i).second * t;

    for (unsigned j = i + 1; j < n; j++) {
      double rj = xv.at(j).first - xv.at(j).second * t;
      if (ri < rj)
        return false;
    }
  }

  return true;
}

int main() {

  cout.setf(ios::fixed);
  cout.precision(10);

  cin >> n;

  xv.resize(n);

  rep(i, n) { cin >> xv.at(i).first; }
  rep(i, n) { cin >> xv.at(i).second; }

  sort(xv.begin(), xv.end(),
       [](auto &a, auto &b) { return a.first < b.first; });

  double l = -100000000000.0;
  double r = -l;
  double m;

  rep(i, 200) {
    m = (l + r) * .5;
    if (check(m))
      r = m;
    else
      l = m;
  }

  cout << m << endl;
}
