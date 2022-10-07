class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size() + 10];
        
        for(int i = 1;i < nums.size();i ++) dp[i] = 9999999;
        dp[0] = 1;
        
        for(int i = 0;i < nums.size();i ++){
            for(int j = 1;j <= nums[i];j ++)
                if(i + j >= nums.size()) break;
                else dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
        
        return dp[nums.size() - 1] - 1;
    }
};