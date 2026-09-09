class Solution {
public:
    string longestPalindrome(string s) {
        int n =  s.length();
        if(n<=1) return s;
        string result = "";
        for(int i=0;i<n;i++){
            int low = i; // consider odd length
            int high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
                if(low==-1 || high == n)
                break;
            }
            string palindrome = s.substr(low + 1, high - low - 1);
            if(palindrome.length()> result.length()){
                result = palindrome;
            }
            low = i-1; // consider even length
            high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
                if(low==-1 ||high == n)
                break;
            }
            palindrome = s.substr(low + 1, high - low - 1);
            if(palindrome.length()>result.length()){
                result = palindrome;
            }
        }
        return result;
    }
};