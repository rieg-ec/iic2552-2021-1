#include <iostream>
#include <vector>
#include <string>
#include <sstream>  
#include <set>

using namespace std;

vector<int> parse_stdio(const string &line) {
    vector<int> numbers;
    istringstream ss(line);
    string item;
    while(ss >> item) {
        numbers.push_back(stoi(item));
    }

    return numbers;
}

int main() {
    string line;
    getline(cin, line);

    int tests = stoi(line);

    for (int i = 0; i < tests; i++) {
        getline(cin, line);
        int size = stoi(line);
        getline(cin, line);
        vector<int> numbers = parse_stdio(line);
        set<int> numbers_set;
        for (const int &i: numbers)
            numbers_set.insert(i);

        int max = *numbers_set.rbegin();
        int min = *numbers_set.begin();
        
        if (max - min < numbers_set.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
 }
