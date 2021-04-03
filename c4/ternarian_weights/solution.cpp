#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main() {

    string line;
    getline(cin, line);
        
    int tests = stoi(line);

    // algorithm:
    //  1. find starting point by adding up to biggest before given number
    //  2. if biggest >= number, start from 0 upt to biggest
    //  3. else if biggest < number, start one power after <number> and start substract down

    for (int i = 0; i < tests; i++) {
        getline(cin, line);
        int target = stoi(line);
        
        vector<int> powers = {1};
        int power = 0;
        int number = 1;
        int sum_left = 1;
        
        while (number <= target) {
            power += 1;
            number = pow(3, power);
            powers.push_back(number);
            sum_left += number;
        }

        sum_left -= *powers.rbegin();    
 
        if (sum_left >= target) {
            
        } else {
            
        }

    }
}
