class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int len=1;len<=n/2;len++){
            if(n%len!=0) continue;
            string ans = s.substr(0,len);
            string res ="";
            int count = n/len;
            for(int i=0;i<count;i++){
                res+=ans;
            }
            if(res==s) return true;
        }
        return false;
    }
};