#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Position {
    int x = 0;
    int y = 0;

    pair<int, int> walk(const string &s) {
        if (s == "N") { y += 1; }
        else if (s == "S") { y -= 1; }
        else if (s == "W") { x += 1; }
        else if (s == "E") { x -= 1; }

        return make_pair(x, y);
    }
};

int main() {
    string line;
    getline(cin, line);
        
    int tests = stoi(line);  
    getline(cin, line); // ignore blank line

    // algorithm:
    //  1. save max positions in a set
    //  2. if trying to insert an existing position, remove all steps taken since last time max was there
    //  3. repeat
    for (int i = 0; i < tests; i++) {
        getline(cin, line);
        int n_steps = stoi(line);

        Position pos;
        vector<pair<int, int>> route = {make_pair(0, 0)}; 

        for (int i = 0; i < n_steps; i++) {
            getline(cin, line);
            string step = line;
            pair<int, int> new_pos = pos.walk(step);
            if (find(route.begin(), route.end(), new_pos) != route.end()) {
                vector<pair<int, int>> pruned_route;
                int idx = 0;
                while (route.at(idx) != new_pos) {
                    pruned_route.push_back(route.at(idx));
                    idx += 1;
                }

                route = pruned_route;
            }

            route.push_back(new_pos);
        }
    
        if (route.size() == 1)
            cout << 0 << endl;
        else 
            cout << route.size() - 1 << endl;
    
        if (i != tests - 1)
            getline(cin, line);
    }
}
