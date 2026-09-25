class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char it : s) {
            if (it == '(' || it == '{' || it == '[') {
                st.push(it);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else {
                    char ch = st.top();
                    st.pop();
                    if (ch == '(' && it != ')' || ch == '{' && it != '}' || ch == '[' && it != ']') {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};