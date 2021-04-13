#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    // algorithm:
    //  1. loop through points, each new points will be new start if it has no star-pixel neighbour in left/above/above+right 
    //      positions. ~n
    
    string line;
        
    while (getline(cin, line)) {
        stringstream ss(line);
        int w, h;
        ss >> w >> h;
        vector<string> rows;
        int stars = 0;

        getline(cin, line); // avoid extra conditions by parsing first line outside for loop
        rows.push_back(line);
        for (unsigned i = 0; i < w; i++) {
            if (line.at(i) == '-') {
                if (i == 0)
                    stars += 1; continue;

                if (line.at(i - 1) != '-')
                    stars += 1;
            }
        }

        for (int i = 1; i < h; i++) {
            getline(cin, line);
            rows.push_back(line);
            for (int x = 0; x < w; x++) {           
                if (x == 0 && rows.at(i).at(x) == '-'
                        && rows.at(i - 1).at(x) != '-'
                        && rows.at(i-1).at(x+1) != '-') 
                    stars += 1;

                else if ()


            
    
        }
}
