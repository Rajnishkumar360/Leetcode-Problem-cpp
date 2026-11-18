class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int count =0;
        for(int i=0;i<n;i+=2){
        string result = s.substr(i,2);
             if(result[0]!=result[1]){
                count++;
             }
        }
        return count;
    }
};