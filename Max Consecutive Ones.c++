#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxx(vector<int> &arr, int k) {
    int i = 0;
    int n = arr.size();
    int zeroCount = 0;
    int result = 0;
    for(int j = 0; j < n; j++) {
        if(arr[j] == 0) {
            zeroCount++;
        }
        while(zeroCount > k) {
            if(arr[i] == 0) {
                zeroCount--;
            }
            i++;
        }
        result = max(result, j - i + 1);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k ;
    cin >> k;

    cout << maxx(arr, k);
    return 0;
}