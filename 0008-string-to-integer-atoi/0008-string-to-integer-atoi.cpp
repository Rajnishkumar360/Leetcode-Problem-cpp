class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int l = s.size();
        // Remove leading spaces
        while (i < l && isspace(s[i])) {
            i++;
        }
        if (i == l) {
            return 0;
        }
        // Check sign
        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        else if (!isdigit(s[i])) {
            return 0;
        }
        if (i == l) {
            return 0;
        }
        int value = 0;
        // Convert digits
        while (i < l && isdigit(s[i])) {
            int digit = s[i] - '0';
            // Check overflow
            if (value > INT_MAX / 10 ||
                (value == INT_MAX / 10 && digit > INT_MAX % 10)) {
                if (negative) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
            value = value * 10 + digit;
            i++;
        }
        if (negative) {
            return -value;
        }
        else {
            return value;
        }
    }
};