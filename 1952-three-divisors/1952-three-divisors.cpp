class Solution {
public:
    bool isThree(int n) {
        int count = 2;
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                count++;
              if(i != (n/i)) count++;
            }
        }
         return count == 3;
    }
};