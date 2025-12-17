class Solution {
public:
    string createString(string chars, int times){
        string ans = "";
        while(times--){
            ans += chars;
        }
        return ans;
    }
    string decodeString(string s) {
    int n = s.length();
    stack<char> st;
    string chars = "";

    for(int i = 0; i < n; i++){
        if(s[i] != ']'){
            st.push(s[i]);
        }
        else{
            chars = "";
            while(!st.empty() && !isdigit(st.top())){
                if(isalpha(st.top())){
                    chars += st.top();
                }
                st.pop();
            }
            reverse(chars.begin(), chars.end());  // important

            int base = 1, times = 0;
            while(!st.empty() && isdigit(st.top())){
                times = (st.top()-'0')*base + times;  // handles multi-digit numbers
                base *= 10;
                st.pop();
            }

            string str = createString(chars, times);
            for(auto ch : str) st.push(ch);
        }
    }

    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

};