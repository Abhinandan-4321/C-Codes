#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> stack;
    
    for (char digit : num) {
        while (k > 0 && !stack.empty() && digit < stack.top()) {
            stack.pop(); 
            k--;
        }
        
        stack.push(digit);
    }
    
    
    while (k > 0 && !stack.empty()) {
        stack.pop();
        k--;
    }
    
    string result = "";
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }
    
    
    // int i = 0;
    // while (i < result.length() && result[i] == '0') {
    //     i++;
    // }
    // result = (i == result.length()) ? "0" : result.substr(i);
    
    return result;
}

int main() {
    string number;
    cin >> number;

    int k;
    cin >> k;

    cout << removeKdigits(number, k);
    
    return 0;
}


// While there are digits in the stack and the current digit is less than the top digit of the stack
// Remove the top digit from the stack
// Decrement k
// Push the current digit onto the stack
// If there are still remaining digits to be removed (k is not zero), pop the remaining digits from the stack
// Construct the result string from the remaining digits in the stack, ensuring that leading zeroes are removed
// Find the first non-zero digit or return "0" if result is empty