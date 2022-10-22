class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size() + 10;
        
        long long dp[n][2], d[n][2];
        
        if(nums[0] < 0) {
            dp[0][0] = 0;
            dp[0][1] = nums[0];
            d[0][0] = 0;
            d[0][1] = 1;
        }
        else if(nums[0] == 0){
             dp[0][0] = 0;
            dp[0][1] = 0;
            d[0][0] = 0;
            d[0][1] = 0;
        }
        else{
            dp[0][0] = nums[0];
            dp[0][1] = 0;
            d[0][0] = 1;
            d[0][1] = 0;
        }
        
        long long mx = d[0][0];
        for(int i = 1;i < nums.size();i ++){
            if(nums[i] < 0){
                if(nums[i] * dp[i - 1][1] > 0){
                    dp[i][0] = 3; 
                    d[i][0] = d[i - 1][1] + 1;
                }
                else{
                    dp[i][0] = 0;
                    d[i][0] = 1;
                } 
                if(dp[i - 1][0] > 0){
                    dp[i][1] = -3;
                    d[i][1] = d[i - 1][0] + 1;
                }
                else{
                    dp[i][1] = nums[i];
                    d[i][1] = 1;
                }
            }
            else if(nums[i] == 0){
                dp[i][0] = dp[i][1] = d[i][0] = d[i][1] = 0;
            }
            else{
                if(dp[i - 1][0] > 0) d[i][0] = d[i - 1][0] + 1;
                else d[i][0] = 1;
                if(dp[i - 1][1] < 0) d[i][1] = d[i - 1][1] + 1;
                else d[i][1] = 1;
                dp[i][0] = 3;
                if(dp[i - 1][1] == 0) dp[i][1] = 0;
                else dp[i][1] = -3;
            }
            mx = max(mx, d[i][0]);
         
        }
        return int(mx);
    }
};