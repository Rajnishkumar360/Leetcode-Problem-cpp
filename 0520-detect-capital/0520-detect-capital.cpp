class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        bool upper = true;
        bool lower = true;
        bool firstUpper = true;
        for(int i = 0; i < n; i++) {
            if(!(word[i] >= 'A' && word[i] <= 'Z'))
                upper = false;
            if(!(word[i] >= 'a' && word[i] <= 'z'))
                lower = false;
        }
        if(!(word[0] >= 'A' && word[0] <= 'Z'))
            firstUpper = false;
        for(int i = 1; i < n; i++) {
            if(!(word[i] >= 'a' && word[i] <= 'z')) {
                firstUpper = false;
                break;
            }
        }
        return upper || lower || firstUpper;
    }
};