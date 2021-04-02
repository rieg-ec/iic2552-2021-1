#include <iostream>
#include <string>
#include <limits>
#include <array>

using namespace std;

struct Points {
    int a;
    int b;
    int c;
    int rad;

    void switch_points() {
        int c = a;
        a = b;
        b = c;
    }
};

Points line_to_points(const string &line, char delimiter) {
    Points points;
    int index = 0;
    string number = "";
    for (int pos = 0; pos <= line.size(); pos++) {
        if (line[pos] == delimiter || pos == line.size()) {
            int point = stoi(number);
            switch (index) {
                case 0:
                    points.a = point;
                case 1:
                    points.b = point;
                case 2:
                    points.c = point;
                case 3:
                    points.rad = point;
            }
            number = "";
            index += 1;
        } else { 
            number += line[pos]; 
        }
    }
    return points;
}


int main() {
    int n_of_tests;
    cin >> n_of_tests;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignore \n
    
    string line;
    for (int i = 0; i < n_of_tests; i++) {
        getline(cin, line);
        Points points = line_to_points(line, ' ');
        if (points.b < points.a)
            points.switch_points();

        int distance_not_covered = 0;
        if (points.c + points.rad <= points.a || points.c - points.rad >= points.b) {
            distance_not_covered = points.b - points.a;
 
        } else if (points.c - points.rad <= points.a && points.c + points.rad < points.b) {
            distance_not_covered = points.b  - (points.c + points.rad);

        } else if (points.c - points.rad > points.a) {
            if (points.c + points.rad < points.b)
                distance_not_covered = points.b - points.a - (2*points.rad);
            else 
                distance_not_covered = points.c - points.rad - points.a;
        }

        cout << distance_not_covered << endl;
    }
}
