class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int curr_result = 0;
        int curr_sign = 1;
        long long curr_num = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(isdigit(c)){
                curr_num = curr_num * 10 +(c-'0');
            }
            else if(c == '+'){
                curr_result += curr_sign * curr_num;
                curr_num = 0;
                curr_sign = 1;
            }
            else if(c=='-'){
                curr_result += curr_sign * curr_num;
                curr_num = 0;
                curr_sign = -1;
            }
            else if(c=='('){
                st.push(curr_result);
                st.push(curr_sign);
                curr_result = 0;
                curr_sign = 1;
            }
            else if(c==')'){
                curr_result += curr_sign * curr_num;
                curr_num = 0;
                int outer_sign = st.top();
                st.pop();
                int outer_result = st.top();
                st.pop();
                curr_result = outer_result + outer_sign * curr_result;
            }
        }
        if(curr_num !=0){
            curr_result += curr_sign * curr_num;
        }
        return curr_result;
    }
};