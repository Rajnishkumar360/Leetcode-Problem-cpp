class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;
        for(int x : aliceSizes){
            sumA += x;
        } 
        for(int x : bobSizes){
            sumB += x;
        }
        int diff = (sumB - sumA) / 2;
        sort(bobSizes.begin(), bobSizes.end());
        for(int x : aliceSizes) {
            int target = x + diff;
            if(binary_search(bobSizes.begin(), bobSizes.end(), target))
                return {x, target};
        }
        return {};
    }
};