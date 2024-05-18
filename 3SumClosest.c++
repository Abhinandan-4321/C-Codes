#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;
    
    sort(arr.begin(), arr.end());
    
    int minDiff = INT_MAX;
    int resultSum = 0;
    
    for(int i = 0; i < n - 2; i++) { 
        int left = i + 1;
        int right = n - 1;
        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            
            if(sum == target) {
                cout << target;
                return 0; 
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
            
            int diff = abs(sum - target); 
            if(diff < minDiff) {
                resultSum = sum;
                minDiff = diff;
            }
        }
    }
    cout << resultSum; 
    return 0;
}
