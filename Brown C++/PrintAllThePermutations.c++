#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void backTrack(vector<vector<int>> &ans, vector<int> &nums, int index) {
    if(index == nums.size()){
        ans.push_back(nums);
    }

    for(int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        backTrack(ans, nums, index+1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> perms(vector<int> &nums){
    vector<vector<int>> ans;
    backTrack(ans, nums, 0);
    return ans;
}

int main() { 
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n ; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = perms(nums);

    sort(result.begin(), result.end());

    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
    cout << endl;
    }
    
    return 0;
}