class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(digitSum(arr[i])==i){
               return i;
            }
            
        }
        return -1;
    }
};