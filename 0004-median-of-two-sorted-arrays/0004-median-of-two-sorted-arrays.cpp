class Solution {
public:
    vector<int> mergeArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n) {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < m) {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> merged = mergeArray(arr1, arr2);
        int t = merged.size();
        if (t % 2 == 1) {
            return merged[t / 2];
        } else {
            return (merged[t / 2 - 1] + merged[t / 2]) / 2.0;
        }
    }
};
