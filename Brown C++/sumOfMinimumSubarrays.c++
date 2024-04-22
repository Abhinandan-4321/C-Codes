#include <iostream>
#include <vector>
using namespace std;

void miniSubArr(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int min_element = arr[i];
            for(int k = i + 1; k <= j; k++) {
                if(arr[k] < min_element){
                    min_element = arr[k];
                }
            }
            sum += min_element;
        }
    }
    cout << sum << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    miniSubArr(arr);
    
    return 0;
}