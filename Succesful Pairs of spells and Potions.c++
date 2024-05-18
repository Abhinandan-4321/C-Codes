// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> find(vector<int> &spells, vector<int> &potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size();
    int m = potions.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int left = 0;
        int right = m - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(spells[i] * potions[mid] >= success) {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        ans[i] = m - right - 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> spells(n);
    for(int i = 0; i < n; i++) {
        cin >> spells[i];
    }
    int m;
    cin >> m;
    vector<int> potions(m);
    for(int i = 0; i < m; i++) {
        cin >> potions[i];
    }
    
    long long success;
    cin >> success;
    
    vector<int> result = find(spells, potions, success);
    for(auto i : result) {
        cout << i << " ";
    }
    return 0;
}