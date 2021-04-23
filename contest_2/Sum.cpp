#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string addition(string &a, string &b, int &base) {
  string result = "";
  int remainder = 0;

  if (a.size() > b.size()) {
    int diff = a.size() - b.size();
    for (int i = 0; i < diff; i++)
      b.insert(0, "0");
  } else if (b.size() > a.size()) {
    int diff = b.size() - a.size();
    for (int i = 0; i < diff; i++)
      a.insert(0, "0");
  }

  for (int i = b.size() - 1; i > -1; i--) {
    int sum = a.at(i) - 48 + b.at(i) - 48;
    if (remainder)
      sum += remainder;
    result.insert(0, to_string(sum % base));
    remainder = sum / base;
  }

  if (remainder)
    result.insert(0, to_string(remainder));

  return result;
}

int main() {
  string line;
  string a, b;

  getline(cin, line);
  stringstream ss(line);

  ss >> a >> b;

  string merge = a + b;

  int biggest = 0;

  for (int i = 0; i < merge.size(); i++) {
    if (merge.at(i) - 48 > biggest)
      biggest = merge.at(i) - 48;
  }

  int min_base = biggest + 1;

  cout << addition(a, b, min_base).size() << endl;
}
