class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mx[prices.size() + 10];
        
        mx[prices.size()] = 0;
        for(int i = prices.size() - 1;i >= 0;i --){
            mx[i] = max(mx[i + 1], prices[i]);
        }
        int ans = 0;
        for(int i = 0;i < prices.size();i ++){
             ans = max(ans, mx[i + 1] - prices[i]);
        }
        return ans;
    }
};