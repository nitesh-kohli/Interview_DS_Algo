class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                //if stack is not empty then have to check if it has +ve
                //direction asteroid and it's abs value is less it gets destroyed
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                
                //if top of the stack is same as coming asteroid 
                if(!st.empty() && abs(asteroids[i])== st.top())
                    st.pop();
                
                //if stack empty or stack top is -ve we can push the current asteroid
                //as it is also -ve and never collide
                else if(st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
        }

        int s = st.size();
        vector<int> res(s);
        for(int i = s-1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};