class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int level =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                level++;
            }else{
                level--;
                if(s[i-1]=='('){
                    ans += pow(2,level);
                }
            }
            
        }
        return ans;
       
    }
};