#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int binary_search(vector<int> &A, int a, int b, int T) {
  if (a > b || a < 0 || b > A.size() - 1)
    return -1;

  else if (b - a < 2) {
    if (A.at(a) == T)
      return a;
    else if (A.at(b) == T)
      return b;
    else
      return -1;

  } else if (A.at(a) == T) {
    if (a == 0)
      return a;
    else if (A.at(a - 1) == T)
      return binary_search(A, a - 1, b, T);
    else
      return a;

  } else if (A.at(b) == T) {
    if (A.at(b - 1) == T)
      return binary_search(A, a, b - 1, T);
    else
      return b;

  } else {
    int mid = (a + b) / 2;
    if (A.at(mid) > T)
      return binary_search(A, a, mid, T);
    else
      return binary_search(A, mid, b, T);
  }
}

int main() {

  string line;

  getline(cin, line);
  stringstream ss(line);

  int N, Q;

  ss >> N >> Q;

  getline(cin, line);

  ss.str(string());
  ss.clear();

  ss << line;

  vector<int> vec;

  int n;

  while (ss >> n) {
    vec.push_back(n);
  }

  for (int i = 0; i < Q; i++) {
    getline(cin, line);
    cout << binary_search(vec, 0, vec.size() - 1, stoi(line)) << endl;
  }
}
