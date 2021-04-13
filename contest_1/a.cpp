#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int stones_length;
    string stones;

    cin >> stones_length;
    cin >> stones;

    int n_of_removed = 0;
    vector<char> stones_vector(stones.begin(), stones.end());
    for (int i = 0; i < stones_length - 1; i++) 
    {
        if (stones_vector[i] == stones_vector[i + 1]) 
        {
            n_of_removed += 1;
        }
    }
        
    cout << n_of_removed << endl;
}
