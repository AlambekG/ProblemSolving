class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int dp[2*n + 10];
        dp[0] = nums[0];
        
        int ans = nums[0], dd[2*n + 10];
        
        for(int i = 1;i < n;i ++){
            dp[i] = nums[i] + max(dp[i - 1], 0); 
            ans = max(ans, dp[i]);
        }
        
        int sm = 0;
        for(int i = 0;i < 2*n;i ++) dd[i] = 0;
        
        for(int i = n - 1;i >= 0;i --){
            sm += nums[i];
            dd[i] = max(dd[i + 1], sm);
        }
        
        sm = 0;
        for(int i = 0;i < n - 1;i ++){
            sm += nums[i];
            ans = max(ans, sm + dd[i + 1]);
        }
        return ans;
    }
};