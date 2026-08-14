class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>cnt(26,0);
        int l = 0;
        int ans = 0;
        for(int r = 0;r<(int)s.size();r++){
            int idx = s[r]-'a';
            cnt[idx]++;
            while(cnt[idx]>2){
                cnt[s[l]-'a']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};