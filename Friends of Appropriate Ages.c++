// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool req(int a, int b) {
    return!((a <= 0.5 * b + 7) || (a > b) || (b > 100 && a < 100));
}
 
int find(vector<int> &arr) {
    unordered_map<int, int> map;
    int res = 0;
    for(int ages : arr) {
        map[ages]++;
    }
    for(auto &i : map) {
        for(auto &j : map) {
            if(req(i.first, j.first)){
                res += i.second * (j.second - (i.first == j.first) ? 1 : 0) ;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << find(arr);

    return 0;
}