class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>>pq;
        string ans ="";
        for(char c:s){
            freq[c]++;
        }
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        while(pq.size()!=0){
            auto temp = pq.top();
            int freqs = temp.first;
             char ch = temp.second;
            ans +=string(freqs,ch);
            pq.pop();
        }
        return ans;
    }
};