class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefix(n);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        int totalSum = prefix[n-1];
        if(totalSum % 3 !=0)
        return false;;
        int target = totalSum/3;
        for(int i=0;i<n-2;i++){
            if(prefix[i]!=target)
            continue;
            for(int j=i+2;j<n;j++){
                if(prefix[j-1]==2*target)
                return true;
            }
        }
        return false;
    }
};