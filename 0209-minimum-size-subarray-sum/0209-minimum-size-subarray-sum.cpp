class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map <int, int> mp;
        
        mp[0] = nums[0];
        for(int i = 1;i < nums.size();i ++){
             mp[i] = mp[i - 1] + nums[i];
        }
        
        int ans = 0;
        for(int i = 0;i < nums.size();i ++){
            int r = i, l = 0;
            if(mp[r] < target) continue;
            
            while(l <= r){
                int md = (r + l) >> 1;
                int val = mp[i] - mp[md - 1];
                if(val >= target){
                    l = md + 1;
                    if(!ans) ans = i - md + 1;
                    else ans = min(ans, i - md + 1);
                }
                if(val < target) r = md - 1;
            }
        }
        
        return ans;
    }
};