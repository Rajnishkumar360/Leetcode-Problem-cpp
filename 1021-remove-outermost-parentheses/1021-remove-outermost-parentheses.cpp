class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string result = "";
        for(char ch : s){
            if(ch == '('){
                if(level > 0) result += ch; 
                level++;
            } else { // ch == ')'
                level--;
                if(level > 0) result += ch; 
            }
        }
        return result;
    }
};
