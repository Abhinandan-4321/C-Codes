// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int great(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n =  arr.size();
    int ans = 0;
    for(int i = 0, j = 1; j < n; j++) {
        if(arr[i] < arr[j]) {
            ans++;
            i++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << great(arr);

    return 0;
}