#include <iostream>
#include <vector>
#include <string>
#include <sstream>  

using namespace std;

struct Line {
    int x;
    int y;
};

int main() {
    string line;

    getline(cin, line);

    int tests = stoi(line);

    Line line_a;
    Line line_b;
    int x1, y1, x2, y2;
    
    for (int i = 0; i < tests; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        line_a.x = x1, line_a.y = y1;
        line_b.x = x2, line_b.y = y2;

        int a, b;
        Line *biggest_p = NULL;
        if (line_a.y - line_a.x > line_b.y - line_b.x) {
            biggest_p = &line_a;
        } else if (line_a.y - line_a.x < line_b.y - line_b.x) {
            biggest_p = &line_b;
        }

        if (biggest_p == NULL) {
            if (line_a.x != line_b.y)
                cout << line_a.x << " " << line_b.y << endl;
            else
                cout << line_a.y << " " << line_b.x << endl;
        } else if (addressof(line_a) == biggest_p) {
            if (line_a.x != line_b.y) {
                cout << line_a.x << " " << line_b.y << endl;
            } else {
                cout << line_a.y << " " << line_b.y << endl;
            }
        } else if (addressof(line_b) == biggest_p) {
            if (line_b.x != line_a.y) {
                cout << line_a.y << " " << line_b.x << endl;
            } else {
                cout << line_a.x << " " << line_b.y << endl;
            }

        }

   }
}
