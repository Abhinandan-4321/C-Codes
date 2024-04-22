#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void backTrack(vector<string> &result, string current, int left, int right, int n) {
    if(current.size() == 2*n) {
        result.push_back(current);
        return;
    }

    if(left < n) {
        backTrack(result, current + '(', left+1, right, n);
    }

    if(right < left) {
        backTrack(result, current + ')', left, right+1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backTrack(result, "", 0, 0, n);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> paranthesis = generateParenthesis(n);

    for(auto i : paranthesis) {
        cout << i << " ";
    }
    return 0;
}