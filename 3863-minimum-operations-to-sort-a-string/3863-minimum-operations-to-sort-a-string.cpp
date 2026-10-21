class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        if(s==temp)return 0;
        if(s.size()<=2)return -1;
        char mini=*min_element(s.begin(),s.end());
        char maxi=*max_element(s.begin(),s.end());
        int countmini=0;
        int countmaxi=0;
        for(char c:s ){
            if(c==mini)countmini++;
            if(c==maxi)countmaxi++;
        }
        if(s[0]==mini or s[s.size()-1]==maxi){
            return 1;
        }else if((s[0]==maxi and s[s.size()-1]==mini) and (countmini==1 and countmaxi==1) ){
            return 3;
        }else return 2;
    }
};