#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n_of_papers;
    cin >> n_of_papers;
    
    vector<int> papers;

    int citations;

    for (int i = 0; i < n_of_papers; i++) {
        cin >> citations;
        papers.push_back(citations);
    }


    sort(papers.begin(), papers.end());
    reverse(papers.begin(), papers.end());
    
    if (n_of_papers == 1) {
        int out;
        papers[0] == 0 ? out = 0 : out = 1;
        cout << out << endl;
        return 0;
    }
        
    papers.push_back(0); // in case all papers have more citations than n_of_papers
    n_of_papers++;

    for (int i = 0; i < n_of_papers; i++) {
        if (papers[i] <= i) {
            cout << i << endl;
            break;
        }
            
    }
}
