class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        string ans="";
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        for(char ch='z';ch>='a';ch--){
            if(st.count(ch) && st.count(ch-'a'+'A')){
                ans.push_back(ch-'a'+'A');
                return ans;
            }
        }
        return "";
    }
};