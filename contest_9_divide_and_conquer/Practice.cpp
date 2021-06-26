#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

vector<pair<vector<int>, vector<int>>> matches;

void f(vector<int> players, int match) {
  if (players.size() < 2) {
    return;
  } else if (players.size() == 2) {
    matches[match].first.push_back(players[0]);
    matches[match].second.push_back(players[1]);
    return;
  }

  int m = floor(players.size() / 2);
  vector<int> A;
  vector<int> B;

  rep(i, m) {
    A.push_back(players[i]);
    matches[match].first.push_back(players[i]);
  }

  rep(i, players.size() - m) {
    B.push_back(players[i + m]);
    matches[match].second.push_back(players[i + m]);
  }

  f(A, match + 1);
  f(B, match + 1);
}

int main() {
  cin >> N;

  vector<int> players;

  rep(i, N) players.push_back(i);

  matches.resize(N);

  f(players, 0);

  cout << matches.size() << endl;

  for (auto arr : matches) {
    if (arr.first.size() > 0 && arr.second.size() > 0) {
      cout << arr.first.size() << " ";
      for (auto i : arr.first) {
        cout << i << " ";
      }

      cout << endl;
    }
  }
}
