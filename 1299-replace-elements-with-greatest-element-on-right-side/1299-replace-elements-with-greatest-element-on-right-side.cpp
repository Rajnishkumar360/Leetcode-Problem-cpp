class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int temp = -1;
        int maxRight = -1;
        for(int i=n-1;i>=0;i--){
            int temp = arr[i];
            arr[i] = maxRight;
            if(temp > maxRight){
                maxRight = temp;
            }
        }
        return arr;
    }
};