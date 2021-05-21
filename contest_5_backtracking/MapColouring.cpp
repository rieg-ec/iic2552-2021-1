#include <iostream>
#include <set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

int T, C, B, K, a, b;
vector<vector<int>> G;
vector<int> map;

bool solve(int pos) {
  if (pos == C)
    return true;

  set<int> s;
  rep(i, K) s.insert(i + 1); // available colors
  for (int v : G[pos])
    if (map[v])
      s.erase(map[v]); // remove colors already used by neighbours of u

  for (int c : s) {
    map[pos] = c;
    if (solve(pos + 1))
      return true;
    map[pos] = 0;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while (T--) {
    cin >> C >> B;

    G.assign(C, vector<int>());

    rep(_, B) {
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    bool solved = false;
    rep(i, 4) if (!solved) {
      map.assign(C, 0), K = i + 1;
      if (solve(0)) {
        solved = true;
        cout << i + 1 << '\n';
      }
    }

    if (!solved)
      cout << "many\n";
  }
}
