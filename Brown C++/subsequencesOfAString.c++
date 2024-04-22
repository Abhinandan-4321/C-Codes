#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<string> subsequences;
    for(int i = 0; i < (1 << n); i++) {
        string subsequence;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j))
            {
                subsequence += s[j];
            }
        }
        subsequences.push_back(subsequence);
    }
    
    for(auto& i : subsequences) {
        cout << i << " ";
    }
    
    return 0;
}
