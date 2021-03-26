#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

vector<int> line_to_vector(const string &line, char delimiter) {
    vector<int> numbers;
    string number;
    for (char c: line) {
        if (c == delimiter) {
            numbers.push_back(stoi(number));
            number = "";
        } else { 
            number += c; 
        }
    }

    numbers.push_back(stoi(number));

    return numbers;
}

struct Smallest {
    int n;
    int pos;

    void reset(int &num) {
        pos = 0;
        n = num;
    }
};

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int n_of_planks;
        cin >> n_of_planks;

        string line;
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignore \n
        getline(cin, line);
        
        vector<int> planks;
        planks = line_to_vector(line, ' ');

        /*
         * loop through the array, if the smallest number is smaller than the size of the array, remove it.
         * If not, the biggest square has sides the size of the array. (~ square time)
        */
    
        Smallest smallest;

        bool flag = true;
        while (flag) {
            smallest.reset(planks[0]);
            for (int pos = 0; pos < planks.size(); pos++) {
                if (planks[pos] < smallest.n) { 
                    smallest.n = planks[pos];
                    smallest.pos = pos;
                }
            }
            if (smallest.n < planks.size())
                planks.erase(planks.begin() + smallest.pos);
            else
                flag = false;
         
        }               
        
        cout << planks.size() << endl;
    }
    
}
