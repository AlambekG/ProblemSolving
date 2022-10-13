class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), val;
        int dp[n + 10];
        dp[0] = dp[1] = 0;
        for(int i = 1;i < n;i ++){
             if(i > 1) dp[i] = dp[i - 2];
             for(int j = i - 1;j >= 0;j --){
                 val = (prices[i] - prices[j]);
                 if(j > 1) val += dp[j - 2];
                 if(val > dp[i]){
                     dp[i] = val; 
                 }
             }
            dp[i] = max(dp[i], dp[i - 1]);
        } 
        return dp[n - 1];
    }
};