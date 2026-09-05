class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openbr = 0, closebr = 0;
        int start = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') openbr++;
            else closebr++;
            if (openbr == closebr) {
                result += s.substr(start + 1, i - start - 1);
                start = i + 1;
                openbr = closebr = 0;
            }
        }
        return result;
    }
};
