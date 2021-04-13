#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


int main() {
    string line;
    getline(cin, line);
    int n_of_pokemons = stoi(line);
    getline(cin, line);
    string pokemons = line;
    
    set<char, greater<char>> pokemons_set;
    for (char &c: pokemons)
        pokemons_set.insert(c);

    for (int i = 0; i < pokemons.size() - pokemons_set.size(); i++) {
        set<char, greater<char>> pokemons_subset;
        for (int j = 0; j < pokemons_set.size(); j++) {
            pokemons_subset.push_back(pokemons[i + j]);
        }

        if (pokemons_subset = pokemons_set) {

        }
    }
}
