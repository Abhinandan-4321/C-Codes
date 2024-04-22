#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> postToIn(vector<string> &post) {
    stack<string> s;
    int n = post.size();
    
    for(int i = 0; i < n; i++) {
        if(isalnum(post[i][0])){
            s.push(post[i]);
        }
        else{
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            
            string temp = "(" + op1 + " " + post[i] + " " + op2 + ")";
            
            s.push(temp);
        }
    }
    
    vector<string> ans;
    ans.push_back(s.top());
    return ans;
}

int main() {
    string post;
    getline(cin, post);
    
    vector<string> words;
    string word;
    
    stringstream ss(post);
    while(ss >> word) {
        words.push_back(word);
    }
    
    vector<string> result = postToIn(words);
    for(auto i : result) {
        cout << i ;
    }

    return 0;
}