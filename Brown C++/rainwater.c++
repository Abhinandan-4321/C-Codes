// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> left(n);
    vector<int> right(n);
    left[0] = arr[0];
    for(int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }
    
    right[n-1] = arr[arr.size()-1];
    
    for(int i = arr.size() - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (min(left[i], right[i]) - arr[i]);
    }
    
    cout << ans;
    
    // for( auto i : right ) {
    //     cout << i << " ";
    // }
    return 0;
}