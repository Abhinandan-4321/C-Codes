#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


vector<string> functionality(string digit){


    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };


    vector<string> result;


    result.push_back("");


    for(char words:digit){
        vector<string> temp;
        for(char letters: mapping[words-'0']){ // words-0 is just to conver the digit to no. and find it;s correspoonding words set;
            for(string combi: result){
                temp.push_back(combi + letters);
            }
        }
        result = temp;
    }
return result;
}


int main(){
    string digit= "22";
    vector<string> result = functionality(digit);
    sort(result.begin(),result.end());
    for(auto x: result){
        cout<<x<<" ";
    }


    return 0;
}




// Let's dry run the code with the input "23":

// Initialization:

// digit is initialized to "23".
// mapping is initialized to map each digit to its corresponding letters on a phone keypad.
// result vector is initialized with an empty string.
// First Iteration (digit = '2'):

// For each character words in "23":

// words is '2'.
// mapping[words - '0'] gives the string "abc".
// For each character letters in "abc":
// For each combination combi in result:
// Append letters to combi and add it to temp.
// After the inner loop completes, temp contains all combinations formed by appending "a", "b", and "c" to the empty string.

// result is updated to temp.

// Second Iteration (digit = '3'):

// For each character words in "23":

// words is '3'.
// mapping[words - '0'] gives the string "def".
// For each character letters in "def":
// For each combination combi in result (updated from the first iteration):
// Append letters to combi and add it to temp.
// After the inner loop completes, temp contains all combinations formed by appending "d", "e", and "f" to the combinations obtained from the first iteration.

// result is updated to temp.

// Sorting:

// The result vector is sorted lexicographically.
// Output:

// Each combination in the result vector is printed.
// Let's see how the code proceeds:

// Initialization:

// digit = "23"
// mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
// result = {""}
// First Iteration (digit = '2'):

// words = '2'
// mapping[words - '0'] = mapping[2 - '0'] = mapping[2] = "abc"
// For letters in "abc":
// For combi in result = {""}:
// Append letters to combi, yielding {"a", "b", "c"}
// result is updated to {"a", "b", "c"}
// Second Iteration (digit = '3'):

// words = '3'
// mapping[words - '0'] = mapping[3 - '0'] = mapping[3] = "def"
// For letters in "def":
// For combi in result = {"a", "b", "c"}:
// Append letters to combi, yielding {"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"}
// result is updated to {"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"}
// Sorting:

// result is sorted lexicographically to {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}
// Output:

// Each combination in the result vector is printed:
// bash
// Copy code
// ad ae af bd be bf cd ce cf
// So, for the input "23", the code generates all possible combinations of letters that can be formed, which are "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", and "cf".