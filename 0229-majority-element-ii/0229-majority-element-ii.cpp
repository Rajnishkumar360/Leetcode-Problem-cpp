class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
          int n = arr.size();
          vector<int> ans;
          map<int,int> mp;
          int mini = (int)(n/3) + 1;
          for(int i=0; i<n; i++){
              mp[arr[i]]++;
          }
          for(auto &it : mp){
              if(it.second >= mini){
                  ans.push_back(it.first);
              }
          }
          sort(ans.begin(), ans.end());
          return ans;
      }
  };

    