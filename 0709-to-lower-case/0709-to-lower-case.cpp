class Solution {
public:
    string toLowerCase(string s) {
        string res = "";
        for(char c:s){
             if(c>='A' && c<='Z')
             c = c+32;
             res.push_back(c);
        }
        return res;
    }
};