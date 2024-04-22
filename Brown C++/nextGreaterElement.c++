        #include <iostream>
        #include <algorithm>
        #include <stack>
        #include <unordered_map>
        #include <vector>
        using namespace std;

        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
            vector<int> ans;
            unordered_map<int, int> nextGreater;
            stack<int> stk;

            for(int num : nums2) {
                while(!stk.empty() && stk.top() < num) {
                    nextGreater[stk.top()] = num;
                    stk.pop();
                }
                stk.push(num);
            }

            while(!stk.empty()) {
                nextGreater[stk.top()] = -1;
                stk.pop();
            }

            for(int num : nums1) {
                ans.push_back(nextGreater[num]);
            }

            return ans;
        }

        int main() {
            int n;
            cin >> n;
            vector<int> nums1(n);
            for (int i = 0; i < n; i++) {
                cin >> nums1[i];
            }

            int m;
            cin >> m;
            vector<int> nums2(m);
            for (int i = 0; i < m; i++) {
                cin >> nums2[i];
            }

            vector<int> result = nextGreaterElement(nums1, nums2);

            for(int num : result) {
                cout << num << " ";
            }
            cout << endl;


            return 0;
        }




// nums1 = [4, 1, 2]
// nums2 = [1, 3, 4, 2]
// Initialize an empty stack and an empty unordered map nextGreater.
// Iterate through nums2:   
// For the first element 1, the stack is empty. Push 1 onto the stack.
// For the second element 3, 3 is greater than the top of the stack (1). So, 1's next greater element is 3. Pop 1 from the stack and continue.
// For the third element 4, 4 is greater than the top of the stack (3). So, 3's next greater element is 4. Pop 3 from the stack and continue.
// For the fourth element 2, 2 is smaller than the top of the stack (4). So, push 2 onto the stack.
// Now, the stack contains 4 and 2. Since there are no elements to the right of them, set their next greater elements to -1 in the nextGreater map.
// Now, nextGreater contains {1: 3, 3: 4, 4: -1, 2: -1}.
// Iterate through nums1:
// For 4, find its next greater element from nextGreater, which is -1. Push -1 to ans.
// For 1, find its next greater element from nextGreater, which is 3. Push 3 to ans.
// For 2, find its next greater element from nextGreater, which is -1. Push -1 to ans.
// Return ans = [-1, 3, -1].
// So, the final result is [-1, 3, -1], which matches our expectation. This algorithm gives us the correct next greater elements for each element in nums1.