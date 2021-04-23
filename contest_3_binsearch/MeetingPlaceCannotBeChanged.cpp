#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<pair<double, double>> xv;

int main() {

  cout.setf(ios::fixed);
  cout.precision(10);

  cin >> n;

  xv.resize(n);

  rep(i, n) { cin >> xv.at(i).first; }
  rep(i, n) { cin >> xv.at(i).second; }

  sort(xv.begin(), xv.end(),
       [](auto &a, auto &b) { return a.first < b.first; });

  double r = 1e9 + 1;
  double l = 0;
  double m;

  rep(x, 500) {
    m = (l + r) * .5;

    double L = DBL_MIN;
    double R = DBL_MAX;

    rep(i, n) {
      L = max(L, xv.at(i).first - xv.at(i).second * m);
      R = min(R, xv.at(i).first + xv.at(i).second * m);
    }

    if (R < L)
      l = m;
    else
      r = m;
  }

  cout << m << endl;
}
