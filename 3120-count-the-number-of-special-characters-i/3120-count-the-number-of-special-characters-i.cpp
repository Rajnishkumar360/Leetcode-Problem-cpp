class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(word[i]);
        }
        int count =0;
        for(char ch='a';ch<='z';ch++){
            if(st.count(ch) && st.count(ch-'a' + 'A')){
                count++;
            }
        }
        return count;
    }
};