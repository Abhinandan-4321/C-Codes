#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chain(vector<vector<int>> &arr) {
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });
    
    int n = arr.size();
    int val = arr[0][1]; 
    int count = 1;
    if(n < 2) {
        return n;
    }
    
    for(int i = 1; i < n; i++) {
        if(arr[i][0] > val){ 
            count++;
            val = arr[i][1]; 
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr;
    int a, b;
    for(int i = 0; i < n; i++) {
        vector<int> pair;
        cin >> a >> b;
        pair.push_back(a);
        pair.push_back(b);
        arr.push_back(pair); 
    }
    
    cout << chain(arr);

    return 0;
}
