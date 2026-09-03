class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            long long th = 0;
            for(int pile : piles){
                th += (pile + mid -1)/mid; // find ceil value means largest value;
            }
            if(th<=h){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};