// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long skill(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    long long sum = arr[0] + arr[n-1], ans = 0;
    int i = 0;
    int j = n - 1;
    while(i < j) {
        long long temp = arr[i] + arr[j];
        if(temp != sum) {
            return -1;
        }
        ans += arr[i] * arr[j];
        i++;
        j--;
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
    
    cout << skill(arr);

    return 0;
}