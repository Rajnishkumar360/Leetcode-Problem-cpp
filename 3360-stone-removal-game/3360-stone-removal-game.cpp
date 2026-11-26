class Solution {
public:
    bool canAliceWin(int n) {
        if(n>=10 && n<19){
            return true;
        }else if(n>=27 && n<34){
            return true;
        }else if(n>=40 && n<45){
            return true;
        }else if(n>=49){
            return true;
        }
        return false;
    }
};