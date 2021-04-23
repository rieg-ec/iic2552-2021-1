#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<int> decimal_to_binary(const int &number) {
    int max_binary = ceil(log2 (number));
    vector<int> exponents;
    int sum = 0;
    for (int i = max_binary; i >= 0; i--) {
        int n = pow(2, i);
        if (sum + n <= number) {
            sum += n;
            exponents.push_back(1);
        } else {
            exponents.push_back(0);
        }
    }
    
    if (exponents[0] == 0)
        exponents.erase(exponents.begin());
    return exponents;
}

int main() {
    string line;
    getline(cin, line);
    
    vector<int> exponents = decimal_to_binary(stoi(line));
   
    int sum = 0;
    int index = 0;
    for (const int &e: exponents) {
        if (e == 1)
            sum += pow(2, index);
        index += 1;
    }


    cout << sum << endl;
}
