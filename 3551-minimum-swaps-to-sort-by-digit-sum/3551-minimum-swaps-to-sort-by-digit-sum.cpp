class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (long long)digitSum(nums[i]) * 10000000000LL + nums[i];
        }
        vector<long long> temp = arr;
        sort(arr.begin(), arr.end());
        unordered_map<long long, int> mp;
        for (int i = 0; i < n; i++) {
            mp[temp[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] != arr[i]) {
                int ind = mp[arr[i]];
                swap(temp[i], temp[ind]);
                mp[temp[i]] = i;
                mp[temp[ind]] = ind;
                swaps++;
            }
        }

        return swaps;
    }
};