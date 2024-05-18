#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int seq(vector<int> &arr) {
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << seq(arr);

    return 0;
}