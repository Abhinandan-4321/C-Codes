#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> generate(vector<int> &nums ){
    int n = nums.size();
    vector<vector<int>> res;
    for(int i = 0; i < (1 << n); i++) {
        vector<int> subs;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                if (!subs.empty() && subs.back() > nums[j]) {
                    continue;
                }
                subs.push_back(nums[j]);
            }
        }
        if(subs.size() > 1) {
            res.push_back(subs);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());


    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = generate(nums);

    sort(result.begin(), result.end());


    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}