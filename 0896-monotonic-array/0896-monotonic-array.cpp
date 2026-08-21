class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size();
        bool inc = true;
        bool dec = true;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) dec = false;
            if(arr[i] < arr[i-1]) inc = false;
        }

        return inc || dec;
    }
};
