class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n + 10], pp[n + 10];
        dp[0] = 0;
        pp[0] = 0;
        for(int i = 1;i < n;i ++){
             dp[i] = dp[i - 1];
             int l = 0;
             pp[i] = -1;
             if(pp[i - 1] != -1) l = pp[i - 1];
             else l = i - 1;
            
             for(int j = i - 1;j >= l;j --){
                 int val = dp[j] + (prices[i] - prices[j]) - fee;
                 if(val > dp[i]){
                     dp[i] = val;
                     pp[i] = j;
                 }
             }
             if(pp[i] == -1) pp[i] = pp[i - 1];
        } 
        cout << endl;
        return dp[n - 1];
    }
};