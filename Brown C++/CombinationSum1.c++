#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void helper(vector<int> &arr, int i, int target, vector<int> &sol) {
    if(target == 0) {
        ans.push_back(sol);
        return;
    }

    if(target < 0 || i == arr.size()) {return;}

    helper(arr, i + 1, target, sol);
    sol.push_back(arr[i]);
    helper(arr, i, target - arr[i], sol);
    sol.pop_back();
}

vector<vector<int>> combination(vector<int> &arr, int target) {
    vector<int> sol;
    helper(arr, 0, target, sol);
    return ans;
}

int main() { 
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {    
        cin >> arr[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> result = combination(arr, target);

    for(auto i : result) {
        sort(i.begin(), i.end());
    }
    sort(result.begin(), result.end());

    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    if(result.empty()) {
        cout << -1; 
    }
    
    return 0;
}