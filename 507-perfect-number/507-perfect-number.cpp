class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sm = 0;
        for(int i = 1;i < num;i ++) if(num % i == 0) sm += i;
        return sm == num;
    }
};