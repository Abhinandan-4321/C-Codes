#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &nums, int target, int index) {
    if(target == 0) {
        return true;
    }

    if(target < 0  || index >= nums.size()) {
        return false;
    }

    bool include = find(nums, target - nums[index], index + 1);

    bool exclude = find(nums, target , index + 1);

    return include || exclude;
 }

bool isPresent(vector<int> &nums) {
    int sum = 0;
    for(auto i : nums ) {
        sum += i;
    }

    if(sum % 2 != 0) {
        return false;
    }
    return find(nums, sum/2, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if(isPresent(nums)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

}