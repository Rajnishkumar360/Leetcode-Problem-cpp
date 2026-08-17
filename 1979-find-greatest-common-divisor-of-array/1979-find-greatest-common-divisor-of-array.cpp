class Solution {
public:
        int findGCD(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int smallest = *min_element(nums.begin(), nums.end());
        while (largest != 0) {
            int r = smallest % largest;
            smallest = largest;
            largest = r;
        }
        return smallest;
    }
};
    