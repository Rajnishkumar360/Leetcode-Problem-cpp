class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        int ans1 = 0, ans2 = 0;
        for (int x : nums2) s.insert(x);
        for (int x : nums1) {
            if (s.count(x)) ans1++;
        }
        s.clear();
        for (int x : nums1) s.insert(x);
        for (int y : nums2) {
            if (s.count(y)) ans2++;
        }
        return {ans1, ans2};
    }
};

