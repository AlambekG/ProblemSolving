class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       
        int ans = 9999999, sum = 0, left = 0;
        for(int i = 0;i < nums.size();i ++){
            sum += nums[i];
            
            while(sum >= target){
                ans = min(ans, i - left + 1);
                sum -= nums[left ++];
            }
        }
        if(ans == 9999999) return 0;
        return ans;
    }
};