// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find(int index, vector<int>& arr, unordered_map<int, int> &map, int n, int k){
    if(index == n) {
        return 1;
    }
    
    int notPick = find(index + 1, arr, map, n, k);
    int pick = 0;
    if(!(map[arr[index] - k] || map[arr[index] + k])){
        map[arr[index]]++;
        pick = find(index+1, arr, map, n, k);
        map[arr[index]]--;
    }
    return pick + notPick;
}

int answer(vector<int> &arr, int n, int k) {
    unordered_map<int, int> map;
    return find(0, arr, map, n, k) - 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << answer(arr, n, k);

    return 0;
}