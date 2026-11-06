class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        vector<int> result;
        for(int x : freq) {
            if(x > 0) result.push_back(x);
        }
        int distinct = result.size();
        if(distinct <= k) return 0;
        sort(result.begin(), result.end());
        int ans = 0;
        for(int i = 0; i < distinct - k; i++) {
            ans += result[i];
        }
        return ans;
    }
};