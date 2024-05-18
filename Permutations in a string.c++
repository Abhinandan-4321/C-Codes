#include <iostream>
#include <unordered_map>
using namespace std;

bool check(string s1, string s2) {
    int len_s1 = s1.size();
    int len_s2 = s2.size(); 
    
    if(len_s1 > len_s2) {
        return false;
    }
    
    unordered_map<char, int> s1_counter;
    unordered_map<char, int> s2_window;
    
    for(char c : s1) {
        s1_counter[c]++;
    }
    
    for(int i = 0; i < len_s1; i++) {
        s2_window[s2[i]]++; 
    }
    
    for(int i = 0; i <= len_s2 - len_s1; i++) {
        if(s1_counter == s2_window) {
            return true;
        }
        if(i + len_s1 < len_s2) {
            s2_window[s2[i]]--;
            if(s2_window[s2[i]] == 0) {
                s2_window.erase(s2[i]);
            }
            s2_window[s2[i + len_s1]]++;
        }
    }
    return false;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    bool result = check(s1, s2);
    if(result) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
