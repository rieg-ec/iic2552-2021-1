#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>  

using namespace std;

vector<string> line_split(const string &line) {
    string item;
    stringstream ss(line);
    vector<string> elems;
    while (getline(ss, item, ' ')) {
        elems.push_back(move(item));
    }

    return elems;
}

int main() {
    
    string line;
    map<string, int> defs_map;

    while(getline(cin, line)) {
        if (line == "clear")
            break;

        vector<string> expr = line_split(line);

        if (expr[0] == "def") {
            // insert if doesn't exists, else override
            if (defs_map.count(expr[1])) {
                defs_map[expr[1]] = stoi(expr[2]);
            } else {
                defs_map.insert(pair<string, int>(expr[1], stoi(expr[2])));
            }

        } else if (expr[0] == "calc") {
            string match = "unknown";
            if (defs_map.count(expr[1])) {
                int sum = defs_map[expr[1]];

                for (int i = 2; i < expr.size(); i++) {
                    if (expr[i] == "-") {
                        if (defs_map.count(expr[i+1]))
                            sum -= defs_map[expr[i+1]];
                        else
                            break;

                    } else if (expr[i] == "+") {
                        if (defs_map.count(expr[i+1]))
                            sum += defs_map[expr[i+1]];
                        else
                            break;

                    } else if (expr[i] == "=") {
                        for (const auto& [key, val]: defs_map)
                            if (val == sum) 
                                match = key;
                                break;
                    }

                }
            }
                
            for (int i = 1; i < expr.size(); i++) 
                cout << expr[i] << " ";       

            cout << match << endl;   
        }   
    }
}
