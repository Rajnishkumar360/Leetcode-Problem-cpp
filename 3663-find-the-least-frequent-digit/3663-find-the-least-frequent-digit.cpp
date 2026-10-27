class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> freq;
        while(n > 0){
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        int leastDigit = 10;   
        int leastFreq  = INT_MAX;
        for(auto it : freq){
            if(it.second < leastFreq || 
               (it.second == leastFreq && it.first < leastDigit)) {
                leastFreq = it.second;
                leastDigit = it.first;
            }
        }
        return leastDigit;
    }
};
