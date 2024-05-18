    // Online C++ compiler to run C++ program online
    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;

    int count(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int st = 0;
        int end = arr.size() - 1;
        int operation = 0;
        while(st < end) {
            if(arr[st] + arr[end] == k) {
                operation++;
                st++;
                end--;
            }
            else if(arr[st] + arr[end] > k){
                end--;
            }
            else{
                st++;
            }
        }
        return operation;
    }

    int main() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        
        cout << count(arr, k);

        return 0;
    }