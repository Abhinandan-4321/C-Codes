#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int> asteroids){

    stack<int> st;

    for(int ast : asteroids){
        
        bool destroyed = false;

        while(!st.empty() && st.top() > 0 && ast < 0){     //Check if the stack is not empty, the top of the stack is a right-moving asteroid, and the current asteroid is a left-moving asteroid.

            if(st.top() < -ast){      //If the left-moving asteroid is larger, remove the top of the stack as it gets destroyed.
                st.pop();
                continue;
            }

            else if(st.top() == -ast) {    // If the asteroids are of equal size, both get destroyed. Remove the top of the stack and mark as destroyed.
                st.pop();
            }

            destroyed = true;     // If the left-moving asteroid is smaller, it gets destroyed, and we don't add it to the stack. Set destroyed to true and break out of the loop.
            break;
        }

        if(!destroyed){
            st.push(ast);
        }
    }

    vector<int> result(st.size());
    for(int i = result.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;


}

int main(){
    int n;
    cin >> n;
    vector<int> asteroids(n);

    for(int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    vector<int> result;
    result = asteroidCollision(asteroids);

    if(result.empty()){
        cout << "Everything Destroyed";
    }
    else{
        for( int i : result ){
            cout << i << " ";
        }
    }
    return 0;
}



// Approach
// The solution involves simulating the process of asteroids moving and colliding. A stack data structure works well for this simulation because it allows us to easily manage collisions as we iterate through the asteroid array:

// Moving Right (+ve values): If an asteroid is moving to the right, we don't need to consider it for collision immediately, so we push it onto the stack.
// Moving Left (-ve values): If an asteroid is moving to the left, it might collide with the asteroids moving to the right before it (i.e., the asteroids currently in the stack).
// Collision Handling
// When we encounter an asteroid moving left, we check it against the top of the stack (the last right-moving asteroid we encountered):

// If the left-moving asteroid is larger (in absolute value), the right-moving asteroid is "destroyed" (removed from the stack), and we continue checking the next asteroid in the stack against the current left-moving asteroid.
// If the asteroids are of equal size, they both get destroyed. We remove the top of the stack and do not add the left-moving asteroid.
// If the left-moving asteroid is smaller, it gets destroyed, and we don't add it to the stack.
// This process repeats until either the stack is empty, the current asteroid doesn't collide with the one at the top of the stack (i.e., either the stack is empty, the top of the stack is a left-moving asteroid, or the current asteroid is larger and all collisions have been resolved), or the current asteroid is destroyed.