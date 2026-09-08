class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int level = 0;
        int maxdepth = 0;
        for(char c:s){
            if(c == '('){
                level++;
                maxdepth = max(maxdepth,level);
            }
            else if(c==')'){
                level--;
            }
        }
        return maxdepth;
    }
};