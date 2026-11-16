class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += arr[i];
        }
        if(totalSum % 3!=0)
        return false;
        int target = totalSum/3;
        int currSum = 0;
        int count =0;
        for(int i=0;i<n;i++){
            currSum += arr[i];
            if(currSum == target){
                count++;
                currSum = 0;
            }
        }
        return count>=3;
    }
};