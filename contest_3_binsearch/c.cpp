#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;

vector<int> p, v;

bool check(double &t) {
  bool flag = false;
  double prev = -1e9;
  rep(i, n) {
    double pos = p.at(i) + v.at(i) * t;
    if (v.at(i) > 0) {
      prev = max(pos, prev);
      flag = true;
    } else if (flag && pos < prev) {
      return true;
    }
  }

  return false;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(12);

  cin >> n;

  p.resize(n);
  v.resize(n);

  rep(i, n) {
    cin >> p.at(i);
    cin >> v.at(i);
  }

  double m, l = 0, r = pow(10, 18);

  bool collision = false;

  rep(i, 200) {
    m = (l + r) * .5;
    if (check(m))
      collision = true, r = m;
    else
      l = m;
  }

  if (collision)
    cout << (l + r) * .5 << endl;
  else
    cout << -1 << endl;
}
