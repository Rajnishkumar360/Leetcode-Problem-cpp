class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
       // result.reserve(max(num1.length(), num2.length()) + 1);
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = 0;
            int digit2 = 0;
            if (i >= 0) {
                digit1 = num1[i] - '0';
            }
            if (j >= 0) {
                digit2 = num2[j] - '0';
            }
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int curr_digit = sum % 10;
            result.push_back(curr_digit + '0');

            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
