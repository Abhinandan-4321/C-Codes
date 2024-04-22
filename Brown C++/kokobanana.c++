// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minEating(vector<int> &arr, int h) {
    int left = 1;
    int right = *max_element(arr.begin(), arr.end());
    
    while(left < right) {
        int mid = (left + right)/2;
        int hours = 0;
        for(int x : arr) {
            hours += (x + mid - 1) / mid;
        }
        if(hours <= h) {
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int h;
    cin >> h;
    
    cout << minEating(arr, h);

    return 0;
}