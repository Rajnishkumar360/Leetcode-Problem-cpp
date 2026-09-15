class Solution {
public:
    bool helper(const string &s, int left, int right) {
        if (left >= right) return true;             
        if (s[left] != s[right]) return false;      
        return helper(s, left + 1, right - 1);       
    }
    bool isPalindrome(string s) {
        string t;
        for (char c : s) {
            if (isalnum(c)) {
                t.push_back(tolower(c));
            }
        }
        return helper(t, 0, (int)t.size() - 1); 
    }     
};
