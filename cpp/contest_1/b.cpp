#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    steps of the algorithm:
    1. parse the input into an array of integers
    2. loop through the array, and substract each number to the total sum, if the
        resulting number is equal to the current loop element, we found the result
 */
int loops = 0;
vector<int> line_to_vector(string &line) {
    vector<int> numbers;
    string number;
    for (char c: line) {
        if (isspace(c)) {
            numbers.push_back(stoi(number));
            number = "";
        } else { 
            number += c; 
        }
    }

    // last number gets ignored as there's not a space in last char
    numbers.push_back(stoi(number));

    return numbers;
}

int main() {
    string line;

    while (getline(cin, line)) {
        vector<int> numbers = line_to_vector(line);
        int sum = 0;
        for (int n: numbers) { sum += n; }

        for (int n: numbers) {
            if (sum - n == n) {
                cout << n << endl;
                break;
            }
        }
    }
}
