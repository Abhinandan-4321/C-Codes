#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backTrack(vector<vector<int>>& permutations, vector<int>& nums, int index, int k) {
    if(index == nums.size()) {
        permutations.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i) {
        swap(nums[i], nums[index]);
        backTrack(permutations, nums, index + 1, k);
        swap(nums[i], nums[index]);
    }
}

vector<int> getPermutation(int n, int k) {
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    vector<vector<int>> permutations;
    sort(permutations.begin(), permutations.end());
    backTrack(permutations, nums, 0, k);

    return permutations[k - 1];
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> permutation = getPermutation(n, k);

    cout << "The " << k << "-th permutation sequence of numbers from 1 to " << n << " is: ";
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
