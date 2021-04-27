#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

int T;

double t = 100;

struct man {
  double startx, starty, endx, endy;

  double vx() { return (endx - startx) / t; }
  double vy() { return (endy - starty) / t; }
};

man a, b;

double f(double t_) {
  double a_x = a.startx + a.vx() * t_;
  double a_y = a.starty + a.vy() * t_;

  double b_x = b.startx + b.vx() * t_;
  double b_y = b.starty + b.vy() * t_;

  return pow(pow(b_y - a_y, 2) + pow(b_x - a_x, 2), .5);
}

int main() {
  cout.precision(10);

  cin >> T;
  int cn = T;

  while (T--) {
    cin >> a.startx >> a.starty >> a.endx >> a.endy;
    cin >> b.startx >> b.starty >> b.endx >> b.endy;

    double l = 0, r = t;
    double m;

    rep(i, 200) {
      m = (r + l) * .5;
      if (f(l) < f(r))
        r = m;
      else
        l = m;
    }

    cout << "Case " << cn - T << ": " << f(m) << endl;
  }
}
