class Solution {
public:
    bool helper(int i,int j,string &s,string &p){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return true;
        if(i<0 && j>=0){
                for(int k=0;k<=j;k++){
                    if(p[k]!='*') return false;
                }
                return true;
            }
            if(s[i]==p[j]){
                return helper(i-1,j-1,s,p);
            }else if(p[j]=='*'){
                return helper(i-1,j,s,p) || helper(i,j-1,s,p);
            }
        return false;
    }
    bool hasMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        for (int i=n - 1;i >=-1;i--) {
            if (helper(i,m - 1, s, p)) return true;
        }
        return false;
    }
};