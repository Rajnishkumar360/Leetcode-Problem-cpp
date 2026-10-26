class Solution {
public:
    string binaryNumber(int n){
        string s ="";
        while(n>0){
            if(n % 2==0){
                s.push_back('0');
            }else{
                s.push_back('1');
            }
            n/=2;
        }
        return s;
    }
    int minimumFlips(int n) {
       string  binarydigit = binaryNumber(n);
       string original = binarydigit;
       string reversedigit(original.rbegin(),original.rend());
       int count =0;
       int len = original.size();
       for(int i=0;i<len;i++){
        if(reversedigit[i]!=original[i]){
            count++;
        }
       }
    //    int n = original.size();
    //    int m = reversedigit.size();
    //    for(int i=0;i<n;i++){
    //     for(int  j=0;j<m;j++){
    //         if(original[i]==reversedigit[j]){
    //             continue;
    //         }
    // else if(original[i]=='0' && reversedigit[j]=='1'){
    //         reversedigit[j] = '1';
    //         count++;
    //     }
    // else if(original[i]=='1' && reversedigit[j]=='0'){
    //           reversedigit[j]='0';
    //           count++;
        // }
        // }
       
       return count;
    }
};