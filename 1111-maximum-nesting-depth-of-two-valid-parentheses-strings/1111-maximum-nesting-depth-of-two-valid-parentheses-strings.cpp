class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int>ans;
        int count = 0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                st.push('(');
                count++;
                if(count % 2 ==1){
                    ans.push_back(0);
                }else{
                    ans.push_back(1);
                }
        } else{
            if(count % 2 == 0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
            st.pop();
            count--;
          }
        }
        return ans;
    }
};