class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse = 0;
        int original = x;
        if(x < 0) return false;
        if(x == 0) return true;
        while(x > 0){
            long long digit = x % 10;
            reverse = reverse* 10 + digit;
            x = x/10;
        if( reverse == original){
             return true;
        }
        }
        return false;
    }
};