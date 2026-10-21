class Solution {
public:
    int productdigit(int n){
        int product = 1;
        while(n > 0){
            int ld = n % 10;
            product = product* ld;
            n/=10;
        }
        return product;
    }
    int digitsum(int n){
        int sum =0;
        while(n > 0){
            int ld = n % 10;
            sum += ld;
            n/=10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int temp = digitsum(n) + productdigit(n);
        if(n % temp == 0){
            return true;
        }
        return false;
    }
};