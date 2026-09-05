class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result = "";
        for (char ch : s) {
            if (ch == '(') {
                if (st.size()!=0) result += ch;
                st.push(ch);
            } else {
                st.pop();
                if (st.size()!=0) result += ch;
            }
        }
        return result;
    }
};
