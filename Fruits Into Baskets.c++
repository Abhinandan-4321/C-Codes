// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &fruits) {
    int n = fruits.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    map<int, int> map;
    while(j < n) {
        map[fruits[j]]++;
        while(j < n && map.size() > 2) {
            map[fruits[i]]--;
            if(map[fruits[i]] == 0) {
                map.erase(fruits[i]);
            }
            i++;
        }
        j++;
        ans = max(ans, j - i);
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
    
    cout << count(arr);

    return 0;
}