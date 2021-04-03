#include <iostream>
#include <vector>
#include <string>
#include <sstream>  
#include <map>  
#include <algorithm>

using namespace std;

vector<int> parse_stdio(const string &line) {
    vector<int> numbers;
    istringstream ss(line);
    string item;
    while(ss >> item) {
        numbers.push_back(stoi(item));
    }

    return numbers;
}

struct PolynomialVector {
    vector<pair<int, int>> coefficients; // <degree, coefficient>
    
    int degree() {
        int max = 0;
        for (const pair<int, int> &coef: coefficients) {
            if (coef.first > max) 
                max = coef.first;
        }

        return max;
    }

    void sort_by_deg() {
        sort(coefficients.begin(), coefficients.end(), [](auto &left, auto &right) {
            return left > right;
        });
    }
};

PolynomialVector polynomial_product(PolynomialVector &v1, PolynomialVector &v2) {
    vector<pair<int, int>> products;
    for (const pair<int, int> &v1_coef: v1.coefficients) {
        for (const pair<int, int> &v2_coef: v2.coefficients) {
            pair<int, int> product;
            product.first = v1_coef.first + v2_coef.first;
            product.second = v1_coef.second * v2_coef.second;
            products.push_back(product);
        }   
    }

    int v1_d = v1.degree();
    int v2_d = v2.degree();
    int biggest_coef = v1_d + v2_d;

    map<int, int> result;
    for (int i = 0; i < biggest_coef; i++) {
        result.insert(make_pair(i, 0));
    }

    for (const pair<int, int> &deg_coef: products) {
        result[deg_coef.first] += deg_coef.second;
    }

    PolynomialVector polynomial_result;
    for (const auto& [key, value]: result) {
        polynomial_result.coefficients.push_back(make_pair(key, value));
    }

    return polynomial_result;
}

int main() {
    // algorithm:
    //  1. multiply vector of coefficients, save result in tuples of type (degree, coefficient) ~ n^2
    //  2. parse all tuples, save biggest degree ~ n
    //  3. create <degree> keys with value set to 0 ~ n
    //  4. for each tuple, sum the coefficient to the value (degree = key) ~ n

    string line;
    getline(cin, line);

    int tests = stoi(line);

    for (int i = 0; i < tests; i++) {
        vector<PolynomialVector> polynomials;

        for (int i = 0; i < 2; i++) {

            getline(cin, line);
            int polynomial_degree = stoi(line);

            getline(cin, line);
            vector<int> coefficients = parse_stdio(line);
            PolynomialVector polynomial;

            for (int i = 0; i < polynomial_degree + 1; i++) {
                pair<int, int> dc;
                dc.first = polynomial_degree - i;
                dc.second = coefficients[i];
                polynomial.coefficients.push_back(dc);
            }

            polynomials.push_back(polynomial);

        }

        PolynomialVector product = polynomial_product(polynomials[0], polynomials[1]);

        cout << product.degree() << endl;
        
        product.sort_by_deg();
        for (const pair<int, int> &coef: product.coefficients) 
            cout << coef.second << " ";
        cout << endl;
    }
 }
