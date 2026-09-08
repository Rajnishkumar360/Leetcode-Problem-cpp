class Solution{
    public:

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int n = nums1.size(), m = nums2.size();
    int low = 0, high = n;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n + m + 1) / 2 - i;

        int left1, right1, left2, right2;
        if (i == 0) left1 = INT_MIN;

        else left1 = nums1[i - 1];
        if (i == n) right1 = INT_MAX;

        else right1 = nums1[i];
        if (j == 0) left2 = INT_MIN;

        else left2 = nums2[j - 1];
        if (j == m) right2 = INT_MAX;
        
        else right2 = nums2[j];
        if (left1 <= right2 && left2 <= right1) {
            if ((n + m) % 2 == 0) {
                int maxLeft = (left1 > left2) ? left1 : left2;
                int minRight = (right1 < right2) ? right1 : right2;
                return (maxLeft + minRight) / 2.0;
            } else {
                if (left1 > left2) return left1;
                else return left2;
            }
        } else if (left1 > right2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0; 
}
};


