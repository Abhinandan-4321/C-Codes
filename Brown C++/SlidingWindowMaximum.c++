#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxi (vector<int> nums) {
    int max = INT_MIN;
    for(auto i : nums) {                   // making the maximum finding function
        if(i > max) {
            max = i;
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector <int> result;

    int left = 0;
    int right = left + k;

    while(right <= n) {
        vector <int> nums;

        for ( int i = left; i < right; i++) {
            nums.push_back(arr[i]);                //making different windows as asked
        }

        // for( auto i : nums ) {
        //     cout << i << " ";                   //for shownig the sliding window
        // }
        // cout << endl;

        result.push_back(maxi(nums));

        left++;
        right++;
        
    }

    for(auto i : result) {
        cout << i << " ";                          // printing result
    }

    return 0;
}