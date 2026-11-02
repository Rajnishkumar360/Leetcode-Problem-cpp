class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int n = str1.size();
        int m = str2.size();
        int divisor = 1;
        for (int i = 1; i <= min(n, m); i++) {
            if (n % i == 0 && m % i == 0) {
                divisor = i; 
            }
        }
        return str1.substr(0, divisor);
    }
};

    