class Solution {
public:
    int fib(int n) {
        int a = 1, b = 1;
        int x;
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        for(int i = 3;i <= n;i ++){
            x = b + a;
            b = a;
            a = x;
        }
        return x;
    }
};