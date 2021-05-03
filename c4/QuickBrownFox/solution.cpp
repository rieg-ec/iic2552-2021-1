#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
using namespace std;

int N;
string line;

string abcd = "abcdefghijklmnopqrstuvwxyz";

tuple<bool, string> check(string phrase) {
  bool pangram = true;
  string missing = "";
  for (char c : abcd) {
    if (phrase.find(c) == string::npos && c != ' ') {
      missing += c;
      pangram = false;
    }
  }

  return {pangram, missing};
}

int main() {
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  rep(i, N) {
    getline(cin, line);

    transform(line.begin(), line.end(), line.begin(),
              [](char c) { return tolower(c); });

    auto [p, m] = check(line);

    if (p)
      cout << "pangram" << '\n';
    else
      cout << "missing " << m << '\n';
  }
}
