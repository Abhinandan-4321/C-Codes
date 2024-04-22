#include <iostream>
#include <vector>
using namespace std;

long long sumSubArr(vector<int> &arr){
    int n = arr.size();
    long long res = 0;
    for(int i = 0; i < n-1; i++) {
        int maxi = arr[i];
        int mini = arr[i];
        for(int j = i; j < n; j++) {
            if(arr[j] > maxi) {
                maxi = arr[j];
            }
            else if(arr[j] < mini) {
                mini = arr[j];
            }
            res += maxi - mini;
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

    cout << sumSubArr(arr);

    return 0;
}