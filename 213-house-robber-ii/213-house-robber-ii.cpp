class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 10][2];
        
        int ans = 0;
        if(n == 1) return nums[0];
        
        nums[0] *= -1;;
        dp[0][1] = nums[0];
        dp[0][0] = 0;
        
        for(int i = 1;i < n;i ++){
            dp[i][1] = nums[i] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        
        ans = max(dp[n - 1][1], dp[n - 1][0]);
        
        
        int dd[n + 20][2];
        nums[0] *= -1;
        nums[nums.size() - 1] *= -1;
        
        dd[0][1] = nums[0];
        dd[0][0] = 0;
        
        for(int i = 1;i < n;i ++){
            dd[i][1] = nums[i] + dd[i - 1][0];
            dd[i][0] = max(dd[i - 1][1], dd[i - 1][0]);
        }
        ans = max(ans, dd[n - 1][1]);
        ans = max(ans, dd[n - 1][0]);
        return ans;
    }
};