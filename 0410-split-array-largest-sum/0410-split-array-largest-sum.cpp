class Solution {
public:
    int countPartition(vector<int>& arr,int maxSum){
        int partitions = 1;
        long long subarraySum = 0;
        for(int num : arr){
            if(subarraySum + num <= maxSum){
                subarraySum += num;
            }else{
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            int partitions = countPartition(arr,mid);
            if(partitions > k){
                low = mid +1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};