class Solution {
public:
static bool comp(vector<int>&p1,vector<int>&p2){
    return p1[1]<p2[1];
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int count=1;
        int b=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            int c=pairs[i][0];
            if(b<c){
                count++;
                b=pairs[i][1];
            }
        }
        return count;
    }
};