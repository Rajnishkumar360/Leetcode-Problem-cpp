class Solution {
public:
    string binaryNumber(int n) {
        string s = "";
        while (n > 0) {
            if (n % 2 == 0) {
                s.push_back('0');
            } else {
                s.push_back('1');
            }
            n /= 2; 
        }
        return s; 
    }

    int minimumFlips(int n) {
        string binarydigit = binaryNumber(n);
        string original = binarydigit;
        string reversedigit(original.rbegin(), original.rend());
        int count = 0;
        int len = original.size();
        int m = reversedigit.size();
        for (int i = 0; i < len && i < m; i++) {
            if (original[i] == reversedigit[i]) {
                continue;
            } else if (original[i] == '0' && reversedigit[i] == '1') {
                reversedigit[i] = '1';
                count++;
            } else if (original[i] == '1' && reversedigit[i] == '0') {
                reversedigit[i] = '0';
                count++;
            }
        }
        return count;
    }
};
