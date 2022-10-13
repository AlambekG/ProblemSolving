class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 10], pp[n + 10];
        dp[0] = 0;
        pp[0] = -1;
        for(int i = 1;i < n;i ++){
             dp[i] = dp[i - 1];
             int l = 0;
             pp[i] = -1;
             if(pp[i - 1] != -1) l = pp[i - 1];
             else l = i - 1;
            
             for(int j = i - 1;j >= l;j --){
                 if(dp[j] + (prices[i] - prices[j]) > dp[i]){
                     dp[i] = dp[j] + (prices[i] - prices[j]);
                     pp[i] = j;
                 }
             }
        } 
        return dp[n - 1];
    }
};