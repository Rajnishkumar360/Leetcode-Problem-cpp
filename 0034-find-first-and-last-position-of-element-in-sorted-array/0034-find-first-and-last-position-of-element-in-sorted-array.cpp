class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

int ft = 0, lt = nums.size() - 1;
        vector<int> ans(2, -1);

    
        while (ft <= lt) {
            int mid = ft + (lt - ft) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target) ans[0] = mid; 
                lt = mid - 1;
            } else {
                ft = mid + 1;
            }
        }

      
        ft = 0, lt = nums.size() - 1;

        while (ft <= lt) {
            int mid = ft + (lt - ft) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target) ans[1] = mid; 
                ft = mid + 1;
            } else {
               lt = mid - 1;
            }
        }

        return ans;
       
    }
};