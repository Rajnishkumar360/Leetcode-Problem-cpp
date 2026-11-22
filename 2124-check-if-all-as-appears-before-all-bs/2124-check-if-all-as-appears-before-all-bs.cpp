class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i=0;i+1<n;i++){
            int number1 = s[i]-'a';
            int number2 = s[i+1]-'a';
            if(number1>number2){
                return false;
            }
        }
        return true;
    }
};