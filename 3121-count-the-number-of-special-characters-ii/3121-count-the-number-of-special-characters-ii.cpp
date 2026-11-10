class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int>lower(26,-1);
        vector<int>upper(26,-1);
        for(int i=0;i<n;i++){
            char ch = word[i];
            if(ch>='a' && ch<='z'){
                lower[ch-'a'] = i;
            }else{
                if(upper[ch-'A']==-1)
                upper[ch-'A'] = i;
            }
        }
        int count =0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1 && lower[i]<upper[i]){
                count++;
            }
        }
        return count;
    }
};