class Solution {
public:
    int helper(int i,string& sequence, string& word){
        int n = sequence.size();
        int m = word.size();
        if(i+m>n) return 0;
        if(sequence.substr(i,m)==word)
        return 1+helper(i+m,sequence,word);
        
        return 0;
    }
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,helper(i,sequence,word));
        }
        return ans;
    }
};