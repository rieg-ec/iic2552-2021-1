#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
        
    int tests = stoi(line);

    for (int i = 0; i < tests; i++) {
        getline(cin, line);
        int number = stoi(line);
        cout << number << " is ";
        if (number == 1) {
            cout << "odd" << endl;
        }
        else if (number % 2 == 0) {
            cout << "even" << endl;
        }  else {
            cout << "odd" << endl;
        }
    }
 }
