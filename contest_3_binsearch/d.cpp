#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, q;
vector<long long> pos;

bool check(double &r) {
  if (pos.at(0) - r > 0)
    return false;
  for (unsigned i = 1; i < n; i++)
    if (pos.at(i - 1) + r < pos.at(i) - r)
      return false;

  if (pos.back() + r < q)
    return false;

  return true;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(12);

  cin >> n >> q;

  double l = 0;
  double r = q;

  pos.resize(n);

  rep(i, n) { cin >> pos.at(i); }

  sort(pos.begin(), pos.end());

  bool flag = false;
  double m;
  rep(i, 100) {
    m = (l + r) * .5;
    if (check(m)) {
      flag = true;
      r = m;
    } else {
      l = m;
    }
  }

  if (flag)
    cout << m << endl;
  else
    cout << -1 << endl;
}
