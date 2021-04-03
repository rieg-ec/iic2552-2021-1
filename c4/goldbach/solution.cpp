#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool is_prime(const int &n) {
    for (int i = 2; i < ceil(pow(n, 0.5)) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string line;
    getline(cin, line);
        
    int tests = stoi(line);

    // algorithm:
    //  1. computer all primes up to 32000
    //  2. split vector [1:n] in to two equal sized halfs [1:n/2] and [n/2:n]
    //  3. sum numbers from each vector and test if they equal target
    
    vector<int> primes_up_to_limit = {2};

    for (int i = 3; i < 32000; i++) {
        if (is_prime(i)) {
            primes_up_to_limit.push_back(i);
        }
    }
    
    
    for (int i = 0; i < tests; i++) {
        getline(cin, line);
        int target = stoi(line);

        int index_limit = 0;
        int primes_size = primes_up_to_limit.size();
        while (primes_up_to_limit.at(index_limit) < target && index_limit < primes_size - 1) {
            index_limit += 1;
        }

        vector<int> left_half;
        vector<int> right_half;

        for (int i = 0; i < index_limit; i++) {
            if (primes_up_to_limit.at(i) <= target / 2)
                left_half.push_back(primes_up_to_limit.at(i));
            else
                right_half.push_back(primes_up_to_limit.at(i));
        }

        
        vector<pair<int, int>> representations;

        for (int &l: left_half) {
            for (int &r: right_half) {
                if (l + r == target) {
                    representations.push_back(make_pair(l, r));
                }
            }
        }

        int last_left = left_half.back();
        if (last_left == target / 2) {
            representations.push_back(make_pair(last_left, last_left));
        }

        cout << target << " has " << representations.size() << " representation(s)" << endl;
        for (auto &p: representations) {
            cout << p.first << "+" << p.second << endl;
        }
    
        if (i != tests - 1)
            cout << " " << endl;
    }
}
