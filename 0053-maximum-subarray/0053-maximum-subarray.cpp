class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n + 10];
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1;i < n;i ++){
            dp[i] = nums[i] + max(dp[i - 1], 0);
            ans = max(ans, dp[i]);
        } 
        return ans;
    }
};