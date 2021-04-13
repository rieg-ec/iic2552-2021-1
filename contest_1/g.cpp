#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

array<int, 4> line_to_vector(string &line) {
    array<int, 4> numbers;
    int index = 0;
    string number = "";
    for (int i = 0; i < line.size(); i++) {
        if (!isspace(line[i])) {
             number += line[i];
        } else { 
            numbers[index] = stoi(number);
            number = "";
            index += 1;
        }
    }

    numbers[3] = stoi(number);

    // order numbers so x1 < x2 and y1 < y2
    if (numbers[0] > numbers[2]) {
        int c = numbers[2];
        numbers[2] = numbers[0];
        numbers[0] = c;
    }

    if (numbers[1] > numbers[3]) {
        int c = numbers[3];
        numbers[3] = numbers[1];
        numbers[1] = c;
    }

    return numbers;
}

bool check_points_overlapse(int &x_1, int &y_1, int &x_2, int &y_2) {
    if (x_1 != x_2 || y_1 != y_2) { return false; }
    return true;
}

int main() {

    array<array<int, 4>, 4> lines;
    for (int i = 0; i < 4; i++) {
        string line;
        getline(cin, line);
        lines[i] = line_to_vector(line);
    }

    array<array<int, 4>, 2> vertical_lines;
    array<array<int, 4>, 2> horizontal_lines;
    int vertical_index = 0, horizontal_index = 0;

    for (int i = 0; i < 4; i++) {
        /* test wether the four lines are parallel to the x and y axis */
        if (lines[i][1] == lines[i][3]) {
            // horizontal line
            horizontal_lines[horizontal_index] = lines[i];
            horizontal_index += 1;
        } else if (lines[i][0] == lines[i][2]) {
            vertical_lines[vertical_index] = lines[i];
            vertical_index += 1;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    // order horizontal lines by their y-pos
    if (horizontal_lines[0][1] > horizontal_lines[1][1]) {
        array<int, 4> c;
        c = horizontal_lines[0];
        horizontal_lines[0] = horizontal_lines[1];
        horizontal_lines[1] = c;
    }

    // order vertical lines by their x-position
    if (vertical_lines[0][0] > vertical_lines[1][0]) {
        array<int, 4> c;
        c = vertical_lines[0];
        vertical_lines[0] = vertical_lines[1];
        vertical_lines[1] = c;
    }

    // check if any lines share more than 1 point
    if (vertical_lines[0][0] == vertical_lines[1][0] ||
            horizontal_lines[0][1] == horizontal_lines[1][1]) {
        // may have area of size 0 a.k.a a 1D line 
        cout << "NO" << endl;
        return 0;
    }


    if (!check_points_overlapse(vertical_lines[0][0], vertical_lines[0][1], 
                                horizontal_lines[0][0], horizontal_lines[0][1])) {
        cout << "NO" << endl;
        return 0;
    } else if (!check_points_overlapse(vertical_lines[0][2], vertical_lines[0][3], 
                                        horizontal_lines[1][0], horizontal_lines[1][1])) {
        cout << "NO" << endl;
        return 0;
    } else if (!check_points_overlapse(vertical_lines[1][2], vertical_lines[1][3],
                                        horizontal_lines[1][2], horizontal_lines[1][3])) {
        cout << "NO" << endl;
        return 0; 
    } else if (!check_points_overlapse(vertical_lines[1][0], vertical_lines[1][1],
                                        horizontal_lines[0][2], horizontal_lines[0][3])) {
        cout << "NO" << endl;
        return 0; 
    }

    cout << "YES" << endl;
}
