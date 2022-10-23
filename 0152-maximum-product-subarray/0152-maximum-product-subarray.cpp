class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() + 10;
        
        long long dp[n][2];
        
        if(nums[0] < 0) {
            dp[0][0] = 0;
            dp[0][1] = nums[0]; 
        }
        else if(nums[0] == 0){
             dp[0][0] = 0;
            dp[0][1] = 0; 
        }
        else{
            dp[0][0] = nums[0];
            dp[0][1] = 0; 
        }
        
        long long mx = nums[0];
        for(int i = 1;i < nums.size();i ++){
            if(nums[i] < 0){
                if(nums[i] * dp[i - 1][1] > 0) 
                    dp[i][0] = nums[i] * dp[i - 1][1]; 
                else dp[i][0] = 0;
                if(dp[i - 1][0] > 0) dp[i][1] = dp[i - 1][0] * nums[i];
                else dp[i][1] = nums[i];
            }
            else if(nums[i] == 0){
                dp[i][0] = dp[i][1] = 0;
            }
            else{
                dp[i][0] = nums[i];
                if(dp[i - 1][0] > 0) dp[i][0] *= dp[i - 1][0];
                if(dp[i - 1][1] != 0)   
                    dp[i][1] = dp[i - 1][1] * nums[i];
                else dp[i][1] = 0;
            }
            mx = max(mx, dp[i][0]);
    }
        return mx;
    }
};