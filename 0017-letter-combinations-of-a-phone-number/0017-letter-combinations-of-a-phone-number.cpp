class Solution {
public:
    vector<string> result;
    vector<string>mapping={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    void backtrack(string &digits,int idx,string curr){
        if(idx==digits.size()){
            result.push_back(curr);
            return;
        }
        string letters=mapping[digits[idx]-'0'];
        for(char c:letters){
            backtrack(digits,idx+1,curr+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        backtrack(digits,0,"");
        return result;
    }
};