class Solution {
public:
    bool selfdivide(int num){
        int temp = num;
        while(temp>0){
            int ld = temp % 10;
            if(ld==0 || num % ld!=0) return false;
            temp/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left;i<=right;i++){
            if(selfdivide(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};