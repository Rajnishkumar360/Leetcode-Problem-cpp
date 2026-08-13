class Solution {
public:
    bool helper(int i, int j, string& s, string& t) {
        if (i == s.size()) return true;   
        if (j == t.size()) return false;  
        if (s[i] == t[j]) {
            return helper(i + 1, j + 1, s, t);
        } else {
            return helper(i, j + 1, s, t);
        }
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        return helper(0, 0, s, t);
    }
};
