class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        long long curr_num = 0;
        char last_operator = '+';
        int n = s.length();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(isdigit(c)){
                curr_num = curr_num * 10 +(c-'0');
            }
            if((!isdigit(c)) && (!isspace(c)) || i == n-1){
                if(last_operator == '+'){
                    st.push_back(curr_num);
                }
                else if(last_operator == '-'){
                    st.push_back(-curr_num);
                }
                else if(last_operator == '*'){
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top * curr_num);
                }
                else if(last_operator == '/'){
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top/curr_num);
                }
                last_operator = c;
                curr_num = 0;
            }
        }
        int final_result = 0;
        for(int value : st){
            final_result += value;
        }
        return final_result;
    }
};