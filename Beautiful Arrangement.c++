#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backTrack(int& count, vector<int>& nums, int index) {
    if (index == nums.size()) {
        count++;
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        if ((index + 1) % nums[index] == 0 || nums[index] % (index + 1) == 0) {
            backTrack(count, nums, index + 1);
        }
        swap(nums[i], nums[index]);
    }
}

int countArrangement(int n) {
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    int count = 0;
    backTrack(count, nums, 0);
    return count;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = countArrangement(n);
    cout << "Number of beautiful arrangements: " << result << endl;

    return 0;
}
