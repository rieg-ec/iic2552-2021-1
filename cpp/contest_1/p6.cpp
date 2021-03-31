#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int main() {
    /* algorithm steps:
     *  1. find the longest line -> that is the rectangle width
     *  2. for each line, calculate (longest_line - current_line)/2 -> padding
     *  3. apply the padding on the go
    */

    string line;
    vector<string> lines;
    int max_size = 0;
    while (getline(cin, line)) {
        lines.push_back(line);
        if (line.size() > max_size) { max_size = line.size(); }
    }

    cout << string(max_size + 2, '*') << endl;
    bool left_turn = true;
    
    for (int i = 0; i < lines.size(); i++) {
        // if the padding is an odd number, round down the left size and round up right side
        double padding = (max_size - lines[i].size()) / 2.0;

        int left_padding = floor(padding);
        int right_padding = ceil(padding);
        
        if (left_padding != right_padding) {
            if (!left_turn) {
                left_turn = true;
                int c = left_padding;
                left_padding = right_padding;
                right_padding = c;
            } else {
                left_turn = false;
            }
        }

        lines[i] = "*" + string(left_padding, ' ') + lines[i] + string(right_padding, ' ')  + "*";
        cout << lines[i] << endl;
    }   

    cout << string(max_size + 2, '*') << endl;
}
