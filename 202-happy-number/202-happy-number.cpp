class Solution {
public:
    int fun(int x){
        int a = 0;
        while(x > 0){
            a = a + (x % 10) * (x % 10);
            x /= 10;
        }
        return a;
    }
    bool isHappy(int n) {
        for(int i = 1;i < 1000;i ++){
            n = fun(n);
            if(n == 1) return true;
        }
        return false;
    }
};