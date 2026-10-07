class Solution {
public:
    int n;
    unordered_set<string>st;
    int maxLen;
    void helper(string& s,int i,string& curr,int count){
        if(count < 0) return;
        if(i==n){
            if(count == 0){
                if(curr.length()>maxLen){
                    maxLen = curr.length();
                    st.clear();
                }
                if(curr.length()==maxLen){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i] != '(' && s[i]!=')'){ // alphabets
            curr.push_back(s[i]);
            helper(s,i+1,curr,count);
            curr.pop_back();
            return;

        }
        curr.push_back(s[i]);
        helper(s,i+1,curr,count + (s[i] =='(' ? 1 : -1));
        curr.pop_back();
        helper(s,i+1,curr,count);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        st.clear();
        string curr="";
        helper(s,0,curr,0);
        return vector<string>(begin(st),end(st));
    }
};