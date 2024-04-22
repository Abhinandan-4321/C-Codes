#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

vector<string> postToPre(vector<string> post_exp) {
    stack<string> stk;

    int n = post_exp.size();

    for(int i = 0; i < n; i++) {
        if(isOperator(post_exp[i][0])) {
            string op1 = stk.top();
            stk.pop();

            string op2 = stk.top();
            stk.pop();

            string temp = post_exp[i] + " " + op2 + " " + op1;

            stk.push(temp);
        }
        else{
            stk.push(post_exp[i]);
        }
    }
    vector<string> ans;
    ans.push_back(stk.top());
    return ans;
}

int main() {
    string post_exp;
    getline(cin, post_exp);

    vector<string> words;
    string word;

    stringstream ss(post_exp);
    while(ss >> word) {
        words.push_back(word);
    }

    vector<string> ans = postToPre(words);
    for(auto i : ans) {
        cout << i;
    }
    return 0;
}





// #include <iostream>
// #include <algorithm>
// #include <sstream>
// #include <stack>
// #include <vector>
// using namespace std;

// vector<string> postToPre(vector<string> post_exp) {
//     stack<string> stk;

//     int n = post_exp.size();

//     for(int i = 0; i < n; i++) {
//         if (isalnum(post_exp[i][0])){
//             stk.push(post_exp[i]);
//         }
//         else {
//             string op1 = stk.top();
//             stk.pop();

//             string op2 = stk.top();
//             stk.pop();

//             string temp = post_exp[i] + " " + op2 + " " + op1;

//             stk.push(temp);
//         }
        
//     }
//     vector<string> ans;
//     ans.push_back(stk.top());
//     return ans;
// }

// int main() {
//     string post_exp;
//     getline(cin, post_exp);

//     vector<string> words;
//     string word;

//     stringstream ss(post_exp);
//     while(ss >> word) {
//         words.push_back(word);
//     }

//     vector<string> ans = postToPre(words);
//     for(auto i : ans) {
//         cout << i;
//     }
//     return 0;
// }