#include <iostream>

using namespace std;

int N;

long long memoization[100000];

long long fibo(int n) {
  if (n < 2) {
    return n;
  }

  if (memoization[n] != -1) {
    return memoization[n];
  }

  return memoization[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
  cin >> N;

  memset(memoization, -1, sizeof(memoization) / sizeof(long long));

  for (int i = 2; i < N; i++) {
    cout << fibo(i) << '\n';
  }
}
