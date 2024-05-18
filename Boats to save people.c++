#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int boats(vector<int> &arr, int limit) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int boats = 0;
    int i = 0;
    int j = n - 1;
    while(i <= j) {
        if(arr[i] + arr[j] <= limit) {
            i++;
        }
        j--;
        boats++;
    }
    return boats;
}

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << boats(arr, limit);
    return 0;
}