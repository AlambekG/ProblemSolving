class Solution {
public:
    int tribonacci(int n) {
        int d[n + 10];
        d[0] = 0;
        d[1] = 1;
        d[2] = 1;
        for(int i = 3; i <= n;i ++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        return d[n];
    }
};