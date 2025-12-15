class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& tok : tokens) {
        if (tok.size() > 1 || isdigit(tok[0])) {
            st.push(stoi(tok));
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (tok[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

};