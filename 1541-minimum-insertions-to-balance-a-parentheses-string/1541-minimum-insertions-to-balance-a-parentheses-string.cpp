class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int res = 0;
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    if (open > 0) {
                        open--;
                    } else {
                        res++;
                    }
                    i++;
                } else {
                    if (open > 0) {
                        open--;
                        res++;
                    } else {
                        res += 2;
                    }
                }
            }
        }
        res += open * 2;
        return res;
    }
};
