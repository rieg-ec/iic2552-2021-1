#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  string item;

  while (getline(cin, item)) {
    int tests = stoi(item);

    for (unsigned i = 0; i < tests; i++) {
      getline(cin, item);
      int n_pizzas = stoi(item);

      for (unsigned x = 0; x < n_pizzas; x++) {
        getline(cin, item); // ignore pizza name
        getline(cin, item);
        stringstream ss(item);
        string ingredient;
        int n_igredients;

        ss >> n_igredients;

        for (unsigned igr = 0; igr < n_igredients; igr++) {
          ss >> ingredient;
        }

        getline(cin, item);
        ss << item;
        ss >> n_igredients;
        vector<string> ingredients;

        for (unsigned igr = 0; igr < n_igredients; igr++) {
          ss >> item;
          ingredients.push_back(item);
        }
      }
    }
  }
