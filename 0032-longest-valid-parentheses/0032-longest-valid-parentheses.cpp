class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> st; 
        int n = str.length();
        st.push(-1);  
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '(') {
                st.push(i);
            } 
            else {  
                st.pop();  
                if(st.size()==0) {
                    st.push(i); 
                } else {
                    count = max(count, i - st.top());
                }
            }
        }
        return count;
    }
};