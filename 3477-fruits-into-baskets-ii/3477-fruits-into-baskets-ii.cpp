class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int count =0;
        for(int i=0;i<n;i++){
            bool found = false;
            for(int j=0;j<n;j++){
               if(fruits[i]<=baskets[j]){
                baskets[j] = -1;
                found = true;
                break;
               }
            }
            if(!found){
                count++;
            }
        }
        return count;
    }
};