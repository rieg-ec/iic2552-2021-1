#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int T;

double b, c;

double f(double x) { return (pow(x, 2) + b * x + c) / sin(x); }

int main() {
  cout.precision(10);

  cin >> T;

  while (T--) {
    cin >> b >> c;

    double l = 0, r = M_PI / 2 - 1e-10;

    for (int i = 0; i < 60; i++) {
      double midl = l + (r - l) / 3;
      double midr = r - (r - l) / 3;

      if (f(midl) < f(midr))
        r = midr;
      else
        l = midl;
    }

    cout << f((l + r) * .5) << endl;
  }
}
