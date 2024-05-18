// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxx(string &s, int k) {
    int left = 0;
    int right = 0;
    int n = s.size();
    int count = 0;
    int ans = 0;
    while(right < n) {
        if(s[right] == 'T'){
            count++;
        }
        while(count > k) {
            if(s[left] == 'T' ) {
                count--;
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    
    count = 0;
    left = 0;
    right = 0;
    
    while(right < n) {
        if(s[right] == 'F') {
            count++;
        }
        while(count > k) {
            if(s[left] == 'F') {
                count--;
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    cout << maxx(s, k);

    return 0;
}