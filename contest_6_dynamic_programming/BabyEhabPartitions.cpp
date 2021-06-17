#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

bool check(vector<int> arr) {
  /*
   * returns true arr can be divided into 2 partitions where the sum is
   * equal
   */
  vector<int> A = {};
  vector<int> B = {};

  A.resize(arr.size()), B.resize(arr.size());
  int sum;

  sum = 0;
  rep(i, arr.size()) { sum += arr[i]; }
  if (sum % 2 != 0) {
    return false;
  }

  sum = 0;
  rep(i, arr.size()) {
    sum += arr[i];
    A[i] = sum;
  }

  sum = 0;
  for (int i = arr.size() - 1; i >= 0; i--) {
    sum += arr[i];
    B[i] = sum;
  }

  rep(i, arr.size() - 1) {
    if (A[i] == B[i + 1]) {
      return true;
    }
  }

  return false;
}

vector<int> to_remove = {};

pair<int, vector<int>> dp(vector<int> arr, int m, int n,
                          vector<int> to_remove = {}) {

  if (!check(arr)) {
    return make_pair(n, to_remove);
  }

  if (check(arr) && m < 0) {
    return make_pair(1000, to_remove);
  }

  vector<int> arr1 = {};
  vector<int> arr2 = {};

  copy(arr.begin(), arr.end(), back_inserter(arr1));
  copy(arr.begin(), arr.end(), back_inserter(arr2));

  arr2.erase(arr2.begin() + m);

  pair<int, vector<int>> res1 = dp(arr1, m - 1, n, to_remove);

  to_remove.push_back(m);

  pair<int, vector<int>> res2 = dp(arr2, m - 1, n + 1, to_remove);

  if (res1.first < res2.first)
    return res1;

  return res2;
}

int main() {
  int N;
  vector<int> A = {};

  vector<int> C;

  cin >> N;
  C.resize(N);
  rep(i, N) cin >> C[i];

  pair<int, vector<int>> res = dp(C, C.size() - 1, 0);

  cout << res.first << '\n';

  for (auto &i : res.second) {
    cout << i << " ";
  }

  cout << '\n';

  cout << check({6, 3, 9, 12}) << endl;
}
