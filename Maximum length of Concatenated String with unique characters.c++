// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool hasDuplicate(string s1, string s2) {
    int arr[26] = {0};
    
    for(char ch : s1) {
        if(arr[ch - 'a']) {
            return true;
        }
        arr[ch - 'a']++;
    }
    
    for(char ch : s2) {
        if(arr[ch - 'a'] > 0) {
            return true;
        }
    }
    
    return false;
}

int solve(int i, vector<string> &arr, string temp, int n) {
    if(i >= n) {
        return temp.length();
    }
    
    int include = 0;
    int exclude = 0;
    
    if(hasDuplicate(arr[i], temp)) {
        exclude = solve(i + 1, arr, temp, n);
    }
    else{
        include = solve(i + 1, arr, temp + arr[i], n);
        exclude = solve(i + 1, arr, temp, n);
    }
    return max(include, exclude);
}

int maxLen(vector<string> &arr) {
    string temp = "";
    int n = arr.size();
    return solve(0, arr, temp, n);
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << maxLen(arr);

    return 0;
}